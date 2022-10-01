#include <cekeikon.h>

int main() {
  vector<string> vs;
  vsWildCard("/home/hae/haebase/fei/feiFrontCor/*.jpg", vs);
  for (unsigned i=0; i<vs.size(); i++) {
    string nomecomp=vs[i];
    Mat_<COR> ori; le(ori,nomecomp); //tamanho nl,nc=360x260
    string nomearq=semDiret(nomecomp);

    //Mat_<T> copia(Mat_<T> _ent, int li, int ci, int nl, int nc, T backg) {
    Mat_<COR> a=copia(ori, 50,30, 360-2*40, 260-2*30, COR(0,0,0));
    imp(a,nomearq);
  }
}


// 360x260 => 280x200
