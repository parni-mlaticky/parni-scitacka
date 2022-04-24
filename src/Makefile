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

doc:
	doxygen Doxyfile || (printf "\n\033[0;31m]FAILED TO CREATE DOCUMENTATION!\033[0m\n"; false)
	@echo "Documentation created"

run: gui
	cd $(BUILD_DIR) && $(BUILD_DIR)$(APP_SUBDIR)$(APP_EXEC)

# TODO
profile:
	mkdir -p $(BUILD_DIR)standard-deviation
	cd $(BUILD_DIR)standard-deviation && g++ ../../src/standard-deviation/stddev.cpp ../../src/steammath/steammath.cpp -o stddev

mathtest:
	cd $(BUILD_DIR) && qmake ../src/tests.pro && time make || (printf "\n\033[0;31mBUILD FAILED!\033[0m\n"; false)
	@echo
	@printf "\u001b[32mTests build successful (in $(BUILD_DIR)$(TEST_SUBDIR))\u001b[0m\n"

gui:
	cd $(BUILD_DIR) && qmake ../src/app.pro && time make || (printf "\n\033[0;31mBUILD FAILED!\033[0m\n"; false)
	@echo
	@printf "\u001b[32mApplication build successful (in $(BUILD_DIR)$(APP_SUBDIR))\u001b[0m\n"
