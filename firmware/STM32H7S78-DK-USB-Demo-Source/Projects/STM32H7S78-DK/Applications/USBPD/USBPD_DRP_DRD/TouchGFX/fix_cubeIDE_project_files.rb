require 'fileutils'

# Constants for file paths
PROJECT_FILE_PATH = "../STM32CubeIDE/Appli/.project"
CPROJECT_FILE_PATH = "../STM32CubeIDE/Appli/.cproject"
TEMP_PROJECT_FILE = "temp_project.text"
TEMP_CPROJECT_FILE = "temp_cproject.text"

# Step 1: Replace all instances in .project file and remove specific lines
File.open(TEMP_PROJECT_FILE, 'w') do |out_file|
  File.foreach(PROJECT_FILE_PATH) do |line|
    out_file.puts line.gsub("PARENT-1-PROJECT_LOC/TouchGFX/generated/texts/src/", "PARENT-2-PROJECT_LOC/TouchGFX/generated/texts/src/")
  end
end

lines = File.readlines(TEMP_PROJECT_FILE)
File.open(TEMP_PROJECT_FILE, 'w') do |out_file|
  i = 0
  while i < lines.size
    if lines[i].include?("Application/User/TouchGFX/generated/texts/LanguageGb.cpp") ||
        lines[i].include?("Application/User/TouchGFX/generated/texts/Texts.cpp") ||
        lines[i].include?("Application/User/TouchGFX/generated/texts/TypedTextDatabase.cpp")
      # Skip the line before, the current line, and the next 3 lines
      i += 5
    else
      out_file.puts lines[i]
      i += 1
    end
  end
end

# Replace the original .project file with the modified file
FileUtils.mv(TEMP_PROJECT_FILE, PROJECT_FILE_PATH)

# Step 2: Replace specific instances in .cproject file
File.open(TEMP_CPROJECT_FILE, 'w') do |out_file|
  File.foreach(CPROJECT_FILE_PATH) do |line|
    out_file.puts line.gsub(
      'value="../../../../../../../Middlewares/ST/touchgfx/lib/core/cortex_m7/gcc"',
      'value="../../../../../../../../Middlewares/ST/touchgfx/lib/core/cortex_m7/gcc"'
    )
  end
end

# Replace the original .cproject file with the modified file
FileUtils.mv(TEMP_CPROJECT_FILE, CPROJECT_FILE_PATH)