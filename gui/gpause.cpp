#include <gui/gpause.hpp>
#include <gui/gui.hpp>
#include <gui/elements/image.hpp>
#include <gui/elements/button.hpp>
#include <utils.hpp>
#include <fileformat.hpp>
#include <tinyfiledialogs.h>

#define calctoppos(pos) pos*screensz_y/640

extern bool gamerunning;

void resume(){
    changegui(1);
    gamerunning=true;


}



void save(){
    char const* pattern[]={"*.minceworld"};
    char* path=tinyfd_saveFileDialog("Where shall the world be saved?","./",1,pattern,"minceraft world");
    if(path==NULL){
        changegui(1);
        gamerunning=true;
        return;
    }
    save_world(path);
    tinyfd_messageBox("YES!","World saved!","ok","info",1);
    changegui(1);
    gamerunning=true;
}


image gpause_background("guitex/gpause_background.png",0,0,screensz_x,screensz_y,128,72,255);
button gpause_resume_button("Resume",screensz_x/2-96,calctoppos(50),192,64,resume);
button gpause_save_button("Save",screensz_x/2-96+4,calctoppos(50+64+32),192,64,save);


guielement* gpause[]={
    &gpause_background,&gpause_resume_button,&gpause_save_button,(guielement*)0
};
