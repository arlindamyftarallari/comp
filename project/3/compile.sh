#Meta 1
#lex gocompiler.l
#clang -o gocompiler lex.yy.c
#zip -r gocompiler.zip gocompiler.l


#Meta 2
#flex gocompiler.l
#yacc -dy gocompiler.y
#clang -o gocompiler -Wall -Wno-unused-function *.c
#zip -r gocompiler.zip gocompiler.l gocompiler.y structures.h structures.c

#Meta 3
flex gocompiler.l
yacc -d gocompiler.y
clang-3.8 -o gocompiler -Wall -Wno-unused-function *.c
zip -r gocompiler.zip gocompiler.l gocompiler.y abstract_syntax_tree.h abstract_syntax_tree.c symbol_table.h symbol_table.c semantics.h semantics.c


#Meta 4
#flex gocompiler.l
#yacc -d gocompiler.y
#clang-3.8 -o gocompiler -Wall -Wno-unused-function *.c
#zip -r gocompiler.zip gocompiler.l gocompiler.y structures.h structures.c x.c y.c z.c