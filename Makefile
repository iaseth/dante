AMP = @

AR = ${AMP}ar

CC = ${AMP}gcc
CC_FLAGS = -fPIC -Wall

INCLUDE_FLAG = -Iinclude
LINK_FLAG = 

RM = ${AMP}rm -f

DANTE_MODULE_NAMES = dante
DANTE_MODULE_NAMES += dante_dante
DANTE_MODULE_NAMES += dante_quote
DANTE_MODULE_NAMES += dante_canto

DANTE_OBJ_NAMES = ${addsuffix .o, ${DANTE_MODULE_NAMES}}
DANTE_OBJS = ${addprefix build/obj/, ${DANTE_OBJ_NAMES}}

DANTE_STATIC_LIB = build/lib/libdante.a
DANTE_DYNAMIC_LIB = build/lib/libdante.so

default: lib

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

clean:
	${RM} ${DANTE_OBJS}
	${RM} ${DANTE_STATIC_LIB}
	${RM} ${DANTE_DYNAMIC_LIB}


