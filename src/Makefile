BUILD_DIR = ../build/
APP_SUBDIR = gui/
APP_EXEC = gui
TEST_SUBDIR = mathtest/
TEST_EXEC = test

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

# TODO
doc:
	@echo "Not implemented!"

run: gui
	cd $(BUILD_DIR) && $(BUILD_DIR)$(APP_SUBDIR)$(APP_EXEC)

# TODO
profile:
	@echo "Not implemented!"

mathtest:
	cd $(BUILD_DIR) && qmake ../src/tests.pro && make || (echo "\n\033[0;31mBUILD FAILED\033[0m"; false)
	@echo
	@echo "\033[0;32mTests build successful (in $(BUILD_DIR)$(TEST_SUBDIR))\033[0m"

gui:
	cd $(BUILD_DIR) && qmake ../src/app.pro && make || (echo "\n\033[0;31mBUILD FAILED\033[0m"; false)
	@echo
	@echo "\033[0;32mApplication build successful (in $(BUILD_DIR)$(APP_SUBDIR))\033[0m"
