%{
int i=0;
%}


%%
([a-zA-Z0-9])* {i++;}
"\n" {printf("%d\n", i); i = 0;}
%%
int yywrap(void)

{

return 1;

}


int main()

{

freopen("wor.c", "r", stdin);

yylex();

return 0;

}
