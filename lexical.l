%{
#include <stdio.h>
void showError();
%}

numbers ([0-9])+

%%
. {showError(); return OTHER;}
%%

void showError() {
  printf("other input");
}