


// test if surface has texture; 0=no, 1=yes.
// iAtt = GA_ObjTab[gaNr].iatt;
// if(GA_hasTexture(iAtt) == 1)  .. yes
// ((ColRGB*)&GA_ObjTab[gaNr].iatt)->vtex
#define  GA_hasTexture(iAtt)\
  ((ColRGB*)&iAtt)->vtex


// get TextureReference-Index
// i1 = GA_getTexRefInd(iAtt);
// i1 = ((stru_c3c1*)&GA_ObjTab[gaNr].iatt)->b123;
#define GA_getTexRefInd(iAtt)\
  ((stru_c3c1*)&iAtt)->b123
// see also GA_tex_ga2tr


// EOF
