
# If the first argument is "cpp"...
ifeq (rust,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif 

ifeq (cpp,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif


.PHONY: cpp rust
.SILENT:

SRC = $(RUN_ARGS)/$(RUN_ARGS).cpp
OUT = ./build/$(RUN_ARGS)
RS_SRC = $(RUN_ARGS)/src/main.rs

cpp : $(SRC)
	g++ -Wall -std=c++2a $(SRC) -o $(OUT) && $(OUT)

rust : $(RS_SRC)
	cd $(RUN_ARGS); cargo run

$(RS_SRC) : ./$(RUN_ARGS)
	cd $(RUN_ARGS); cargo init



