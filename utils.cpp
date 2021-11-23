#include <SDL_image.h>
#include <blocks.hpp>
#include <iostream>
#include <string>
#include <types.hpp>
#include <utils.hpp>

extern app mainapp;

SDL_Texture *loadtex(std::string file) {
  SDL_Texture *texture;
  texture = IMG_LoadTexture(mainapp.renderer, file.c_str());
  if (!texture) {
    std::cout << "TEXTURE LOAD ERROR: " << file << std::endl;
  } else
    std::cout << "TEXTURE LOADED SUCCESSFULLY:" << file << std::endl;
  return texture;
}

void blit(SDL_Texture *texture, SDL_Rect *clip, SDL_Rect *dest) {

  SDL_RendererFlip flip = (clip->w < 0) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
  SDL_Rect b;
  memcpy(&b, clip, sizeof(b));
  clip->w = abs(clip->w);

  SDL_RenderCopyEx(mainapp.renderer, texture, clip, dest, (double)NULL,
                   (SDL_Point *)NULL, flip);
  memcpy(clip, &b, sizeof(b));
}

void putblocc(u32 type, u32 x, u32 y, u32 sz) {
  SDL_Rect rec{(int)x, (int)y, (int)sz, (int)sz};
  blit(tex, &blockreg[type].tex, &rec);
}

#pragma push
#pragma GCC diagnostic ignored "-Wnarrowing"
void putblocc(u32 type, u32 x, u32 y, u32 sz, u32 wlevel) {
  SDL_Rect rec{(int)x, (int)y + ((float)sz * (1 - (float)wlevel / 16.0f)),
               (int)sz, (int)((float)sz * ((float)wlevel / 16.0f))};
  SDL_Rect texrec{(int)blockreg[type].tex.x, (int)blockreg[type].tex.y,
                  (int)blockreg[type].tex.w, (int)blockreg[type].tex.w};
  blit(tex, &texrec, &rec);
}
void putfont(char in,u32 x,u32 y){
    SDL_Rect rec{(int) x,(int) y,(int)32,(int)64};
    int xindex,yindex;
    if(in>='A'&&in<='Z'){
        xindex=((in-'A')%12)*8;
        yindex=((in-'A')>=12)?16:0;
    }
    SDL_Rect texrec{(int) xindex,(int) yindex,(int)8,(int)16};
      blit(font, &texrec, &rec);

}
#pragma pop
