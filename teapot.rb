
#
#  This file is part of the "Teapot" project, and is released under the MIT license.
#

teapot_version "0.8.0"

define_project "Dream Display" do |project|
	project.add_author "Samuel Williams"
	project.license = "MIT License"
	
	project.version = "0.1.0"
end

define_target "dream-display" do |target|
	target.build do |environment|
		build_directory(package.path, 'source', environment)
	end
	
	target.depends "Language/C++11"
	target.depends "Library/Dream"
	target.depends "Library/Euclid"
	
	target.provides "Library/Dream/Display" do
		append linkflags "-lDreamDisplay"
	end
end

define_target "dream-display-tests" do |target|
	target.build do |environment|
		build_directory(package.path, 'test', environment)
	end
	
	target.run do |environment|
		run_executable("bin/dream-display-test-runner", environment)
	end
	
	target.depends "Library/Dream/Display"
	target.depends "Library/UnitTest"
	
	target.provides "Test/Dream/Display"
end

define_configuration "dream-display" do |configuration|
	configuration.public!
	
	configuration.require "dream"
end

define_configuration "travis" do |configuration|
	configuration[:source] = "https://github.com/dream-framework"
	
	configuration.require "platforms"
	configuration.import "dream-display"
	
	configuration[:run] = ["Test/Dream/Display"]
end
