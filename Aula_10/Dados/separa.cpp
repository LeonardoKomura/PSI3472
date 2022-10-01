#include <cekeikon.h>

struct FOTO {
  int n; int g;
};

int main() {
  FILE* arq=fopen("masculino.txt","r");
  vector<FOTO> masc;
  for (int i=0; i<100; i++) {
    FOTO f; char ch;
    int conta=fscanf(arq,"%d %c\n",&f.n,&ch);
    if (conta!=2) xerro;
    if (ch!='m') xerro;
    f.g=0;
    masc.push_back(f);
  }
  fclose(arq);
  shuffle(masc.begin(), masc.end(), default_random_engine(7));

  arq=fopen("feminino.txt","r");
  vector<FOTO> femi;
  for (int i=0; i<100; i++) {
    FOTO f; char ch;
    int conta=fscanf(arq,"%d %c\n",&f.n,&ch);
    if (conta!=2) xerro;
    if (ch!='f') xerro;
    f.g=1;
    femi.push_back(f);
  }
  fclose(arq);
  shuffle(femi.begin(), femi.end(), default_random_engine(7));

  FILE* treino=fopen("treino.csv","w");
  for (int i=0; i<50; i++) {
    fprintf(treino,"%03da.jpg;%d\n",masc[i].n,masc[i].g);
    fprintf(treino,"%03db.jpg;%d\n",masc[i].n,masc[i].g);
    fprintf(treino,"%03da.jpg;%d\n",femi[i].n,femi[i].g);
    fprintf(treino,"%03db.jpg;%d\n",femi[i].n,femi[i].g);
  }
  fclose(treino);

  FILE* teste=fopen("teste.csv","w");
  for (int i=50; i<75; i++) {
    fprintf(treino,"%03da.jpg;%d\n",masc[i].n,masc[i].g);
    fprintf(treino,"%03db.jpg;%d\n",masc[i].n,masc[i].g);
    fprintf(treino,"%03da.jpg;%d\n",femi[i].n,femi[i].g);
    fprintf(treino,"%03db.jpg;%d\n",femi[i].n,femi[i].g);
  }
  fclose(teste);

  FILE* valida=fopen("valida.csv","w");
  for (int i=75; i<100; i++) {
    fprintf(valida,"%03da.jpg;%d\n",masc[i].n,masc[i].g);
    fprintf(valida,"%03db.jpg;%d\n",masc[i].n,masc[i].g);
    fprintf(valida,"%03da.jpg;%d\n",femi[i].n,femi[i].g);
    fprintf(valida,"%03db.jpg;%d\n",femi[i].n,femi[i].g);
  }
  fclose(valida);
}
