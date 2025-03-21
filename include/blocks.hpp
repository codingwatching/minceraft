#ifndef BLOCKS_HPP_INCLUDED
#define BLOCKS_HPP_INCLUDED

#include <types.hpp>
#include <vector>
struct block{
    unsigned char type;
    float blockdat; //water: howmanyblocksflowed
    unsigned char blockdat2; //water: iswatersrc
    unsigned char wassolid:1;
    unsigned char generated:1;
    unsigned char waterfilled:1;
    unsigned char cavegened:1;
    unsigned char light=7;//max=15;
    unsigned char spawnattempt:1;
    unsigned long long spawnattempt_timestamp,created_timestamp;
}__attribute__((packed));
struct block_entry{
    unsigned char bitfield;  //HAVEGRAV,HAVECOLL,infjmp,unused x 5
    rect tex;
    char* name;
    double cfriction,cgrav,refindex;
    unsigned int breakcounter;

};
/*
if no collision then cfriction means the friction of moving in it and gravity of
being in it
if collision then cfriction means friction of surface and gravity does nothing

*/
void register_block(int val,char havegrav,char havecoll,char infjmp,rect tex,const char* name,double cfriction,double cgrav,double refindex, char wassolid);
extern std::vector <block_entry> blockreg;
block_entry getBlockType(double x, double y);

#endif // BLOCKS_HPP_INCLUDED
