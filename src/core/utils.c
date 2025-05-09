int rnd ( unsigned int range) {
   static  unsigned int rndG = 123456789u;
    rndG = (rndG * 1664525u + 1013904223u);
    unsigned int rnd = rndG % range;
    return rnd;
}
