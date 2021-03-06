AMP = @

AR = ${AMP}ar

CC = ${AMP}gcc
CC_FLAGS = -fPIC -Wall

INCLUDE_FLAG = -Iinclude
LINK_FLAG = 

RM = ${AMP}rm -f

DANTE_MODULE_NAMES = 
DANTE_MODULE_NAMES += types

DANTE_MODULE_NAMES += string
DANTE_MODULE_NAMES += quote
DANTE_MODULE_NAMES += canto
DANTE_MODULE_NAMES += book

DANTE_MODULE_NAMES += dstring
DANTE_MODULE_NAMES += dquote
DANTE_MODULE_NAMES += dcanto
DANTE_MODULE_NAMES += dbook

DANTE_OBJ_NAMES = ${addsuffix .o, ${DANTE_MODULE_NAMES}}
DANTE_OBJS = ${addprefix build/obj/, ${DANTE_OBJ_NAMES}}



DANTE_EXAMPLE_NAMES = 
DANTE_EXAMPLE_NAMES += ten_strings

DANTE_EXAMPLE_EXES = ${addprefix build/examples/, ${DANTE_EXAMPLE_NAMES}}



DANTE_STATIC_LIB = build/lib/libdante.a
DANTE_DYNAMIC_LIB = build/lib/libdante.so

MAIN_SRC = src/dante.c
MAIN_BIN = build/dante

default: examples ${MAIN_BIN}

run: ${MAIN_BIN}
	@./${MAIN_BIN}

${MAIN_BIN}: ${MAIN_SRC} ${DANTE_STATIC_LIB}
	${CC} $^ -o $@ ${INCLUDE_FLAG}

debug:
	${eval AMP := }

${DANTE_OBJS}: build/obj/%.o: lib/%.c include/dante/%.h
	${CC} -c ${CC_FLAGS} $< -o $@ ${INCLUDE_FLAG}


examples: ${DANTE_EXAMPLE_EXES}

${DANTE_EXAMPLE_EXES}: build/examples/%: examples/%.c ${DANTE_STATIC_LIB}
	${CC} $< -o $@ ${DANTE_STATIC_LIB} ${INCLUDE_FLAG}


${DANTE_STATIC_LIB}: ${DANTE_OBJS}
	${AR} rcs $@ $^

${DANTE_DYNAMIC_LIB}: ${DANTE_OBJS}
	${CC} -shared $^ -o $@

lib: ${DANTE_STATIC_LIB} ${DANTE_DYNAMIC_LIB}

redo: clean default



DANTE_TEST_NAMES = creation
DANTE_TEST_NAMES += deletion
DANTE_TEST_EXE_NAMES = ${addsuffix .test, ${DANTE_TEST_NAMES}}
DANTE_TEST_EXES = ${addprefix build/test/, ${DANTE_TEST_EXE_NAMES}}

${DANTE_TEST_EXES}: build/test/%.test: test/%.c ${DANTE_STATIC_LIB}
	${CC} $^ ${DANTE_STATIC_LIB} ${INCLUDE_FLAG} -o $@

test: ${DANTE_TEST_EXES}

clean:
	${RM} ${DANTE_OBJS}
	${RM} ${DANTE_STATIC_LIB}
	${RM} ${DANTE_DYNAMIC_LIB}
	${RM} ${DANTE_TEST_EXES}
	${RM} ${MAIN_BIN}


