AMP = @

AR = ${AMP}ar

CC = ${AMP}gcc
CC_FLAGS = -fPIC -Wall

INCLUDE_FLAG = -Iinclude
LINK_FLAG = 

RM = ${AMP}rm -f

DANTE_MODULE_NAMES = dante
DANTE_MODULE_NAMES += dante_book
DANTE_MODULE_NAMES += dante_quote
DANTE_MODULE_NAMES += dante_canto

DANTE_OBJ_NAMES = ${addsuffix .o, ${DANTE_MODULE_NAMES}}
DANTE_OBJS = ${addprefix build/obj/, ${DANTE_OBJ_NAMES}}

DANTE_STATIC_LIB = build/lib/libdante.a
DANTE_DYNAMIC_LIB = build/lib/libdante.so

MAIN_SRC = src/dante.c
MAIN_BIN = build/dante

default: ${MAIN_BIN}

run: ${MAIN_BIN}
	@./${MAIN_BIN}

${MAIN_BIN}: ${MAIN_SRC} ${DANTE_STATIC_LIB}
	${CC} $^ -o $@ ${INCLUDE_FLAG}

debug:
	${eval AMP := }

${DANTE_OBJS}: build/obj/%.o: lib/%.c include/%.h
	${CC} -c ${CC_FLAGS} $< -o $@ ${INCLUDE_FLAG}

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


