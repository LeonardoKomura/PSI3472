#include <cekeikon.h>
int main() {
  FILE* arq=fopen("genero.txt","r");
  int j; char ch;
  int masc=0; int femi=0;
  for (int i=1; i<=200; i++) {
    int conta=fscanf(arq,"%d %c\n",&j,&ch);
    if (conta!=2) xerro;
    if (j!=i) xerro;
    if (ch=='m') masc=masc+1;
    if (ch=='f') femi=femi+1;
  }
  cout << "masc=" << masc << endl;
  cout << "femi=" << femi << endl;
  fclose(arq);
}
