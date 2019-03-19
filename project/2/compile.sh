#Meta 1
#lex gocompiler.l
#clang -o gocompiler lex.yy.c
#zip -r gocompiler.zip gocompiler.l


#Meta 2
flex gocompiler.l
yacc -d gocompiler.y
clang -o gocompiler -Wall -Wno-unused-function *.c
zip -r gocompiler.zip gocompiler.l gocompiler.y


#Meta 3
#flex uccompiler.l
#yacc -d uccompiler.y
#clang-3.8 -o uccompiler -Wall -Wno-unused-function *.c
#zip -r uccompiler.zip uccompiler.l uccompiler.y headers.h arvore.c simbolos.c semantica.c


#Meta 4
#flex uccompiler.l
#yacc -d uccompiler.y
#clang-3.8 -o uccompiler -Wall -Wno-unused-function *.c
#zip -r uccompiler.zip uccompiler.l uccompiler.y headers.h arvore.c simbolos.c semantica.c gerar_codigo.c