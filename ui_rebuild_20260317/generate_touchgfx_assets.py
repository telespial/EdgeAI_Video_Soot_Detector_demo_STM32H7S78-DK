#!/usr/bin/env python3
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont

ROOT = Path('/home/user/python_projects/EmbeddedX/projects/soot_detector')
APP = ROOT / 'firmware/STM32H7S78-DK-USB-Demo-Source/Projects/STM32H7S78-DK/Applications/USBPD/USBPD_DRP_DRD/TouchGFX'
NEW = ROOT / 'ui_rebuild_20260317'
ASSETS = APP / 'assets/images'
GEN = APP / 'generated/images/src'

main_src = ASSETS / 'Main_bg2.png'
bg_png = NEW / 'Main_bg_landscape_800x480.png'
help_png = NEW / 'Help_overlay_landscape_800x480.png'


def fit_800x480(src: Path) -> Image.Image:
    im = Image.open(src).convert('RGB')
    tw, th = 800, 480
    sw, sh = im.size
    scale = max(tw / sw, th / sh)
    nw, nh = int(sw * scale), int(sh * scale)
    im = im.resize((nw, nh), Image.Resampling.LANCZOS)
    x = (nw - tw) // 2
    y = (nh - th) // 2
    return im.crop((x, y, x + tw, y + th))


def make_help_overlay(base: Image.Image) -> Image.Image:
    ov = base.copy().convert('RGBA')
    dark = Image.new('RGBA', ov.size, (0, 0, 0, 150))
    ov.alpha_composite(dark)
    d = ImageDraw.Draw(ov)

    panel = (80, 60, 720, 420)
    d.rounded_rectangle(panel, radius=24, fill=(12, 20, 52, 220), outline=(102, 229, 255, 255), width=4)

    title_font = ImageFont.load_default()
    body_font = ImageFont.load_default()

    d.text((110, 95), 'HELP MENU', fill=(120, 255, 255, 255), font=title_font)
    lines = [
        'Touch USB-C cable to continue to Host/Device screen.',
        'Tap power area to switch Source/Sink role.',
        'Tap CONTROL PAD area to send pointer movement.',
        '',
        'Tap X in the top-right corner to close this help.'
    ]
    y = 145
    for line in lines:
        d.text((110, y), line, fill=(220, 240, 255, 255), font=body_font)
        y += 36

    d.rounded_rectangle((655, 80, 705, 130), radius=10, fill=(38, 66, 120, 255), outline=(180, 230, 255, 255), width=2)
    d.line((668, 93, 692, 117), fill=(220, 240, 255, 255), width=3)
    d.line((692, 93, 668, 117), fill=(220, 240, 255, 255), width=3)

    return ov.convert('RGB')


def rgb_to_rgb565_le_bytes(im: Image.Image) -> bytes:
    im = im.convert('RGB')
    out = bytearray()
    for r, g, b in im.getdata():
        v = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)
        out.append(v & 0xFF)
        out.append((v >> 8) & 0xFF)
    return bytes(out)


def write_touchgfx_cpp(path: Path, symbol: str, data: bytes, comment: str):
    header = (
        '// Regenerated locally for landscape UI\n'
        '#include <touchgfx/hal/Config.hpp>\n\n'
        'LOCATION_PRAGMA("ExtFlashSection")\n'
        f'KEEP extern const unsigned char {symbol}[] LOCATION_ATTRIBUTE("ExtFlashSection") = {{ // {comment}\n'
    )
    lines = []
    row = []
    for i, byte in enumerate(data):
        row.append(f'0x{byte:02x}')
        if len(row) == 16:
            lines.append('    ' + ', '.join(row) + ',')
            row = []
    if row:
        lines.append('    ' + ', '.join(row) + ',')
    footer = '\n};\n'
    path.write_text(header + '\n'.join(lines) + footer)


def main():
    bg = fit_800x480(main_src)
    help_ov = make_help_overlay(bg)

    bg.save(bg_png)
    help_ov.save(help_png)

    # Keep assets in sync with generated sources
    bg.save(ASSETS / 'Main_bg.png')
    bg.save(ASSETS / 'Main_bg2.png')
    help_ov.save(ASSETS / 'Info_Overlay.png')

    write_touchgfx_cpp(GEN / 'image_Main_bg.cpp', 'image_main_bg', rgb_to_rgb565_le_bytes(bg), '800x480 RGB565 pixels.')
    write_touchgfx_cpp(GEN / 'image_Main_bg2.cpp', 'image_main_bg2', rgb_to_rgb565_le_bytes(bg), '800x480 RGB565 pixels.')
    write_touchgfx_cpp(GEN / 'image_Info_Overlay.cpp', 'image_info_overlay', rgb_to_rgb565_le_bytes(help_ov), '800x480 RGB565 pixels.')

    print('Generated:')
    print(bg_png)
    print(help_png)
    print(GEN / 'image_Main_bg.cpp')
    print(GEN / 'image_Main_bg2.cpp')
    print(GEN / 'image_Info_Overlay.cpp')


if __name__ == '__main__':
    main()
