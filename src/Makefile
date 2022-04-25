BUILD_DIR = ../build/
APP_SUBDIR = gui/
APP_EXEC = gui
TEST_SUBDIR = mathtest/
TEST_EXEC = test
PROFILE_SUBDIR = standard-deviation
PROFILE_EXEC = stddev

.PHONY: all pack clean test doc run profile mathtest gui

all: gui

# TODO
pack: gui
	@echo "Not implemented!"

# I hope this doesn't brick any machines...
clean:
	rm -r $(BUILD_DIR)*

test: mathtest
	cd $(BUILD_DIR) && $(BUILD_DIR)$(TEST_SUBDIR)$(TEST_EXEC)

doc:
	doxygen Doxyfile || (printf "\n\033[0;31m]FAILED TO CREATE DOCUMENTATION!\033[0m\n"; false)
	@echo "Documentation created"

run: gui
	cd $(BUILD_DIR) && $(BUILD_DIR)$(APP_SUBDIR)$(APP_EXEC)

profile:
	cd $(BUILD_DIR) && qmake ../src/stddev.pro && time make || (printf "\n\033[0;31mBUILD FAILED!\033[0m\n"; false)
	@echo
	@printf "\033[32mProfiler build successful (in $(BUILD_DIR)$(PROFILE_SUBDIR))\033[0m\n"

mathtest:
	cd $(BUILD_DIR) && qmake ../src/tests.pro && time make || (printf "\n\033[0;31mBUILD FAILED!\033[0m\n"; false)
	@echo
	@printf "\033[32mTests build successful (in $(BUILD_DIR)$(TEST_SUBDIR))\033[0m\n"

gui:
	cd $(BUILD_DIR) && qmake ../src/app.pro && time make || (printf "\n\033[0;31mBUILD FAILED!\033[0m\n"; false)
	@echo
	@printf "\033[32mApplication build successful (in $(BUILD_DIR)$(APP_SUBDIR))\n\033[0m"
