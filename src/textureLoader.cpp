#include "../include/textureLoader.h"

textureLoader::textureLoader()
{
    //ctor
}

textureLoader::~textureLoader()
{
    //dtor
}
void textureLoader::loadTexture(char* fileName, GLuint& tId)
{
    glGenTextures(1,&tId);                                                                  // Generates 1 texture id

    glBindTexture(GL_TEXTURE_2D,tId);                                                       // Binds a 2D texture into tId

    image = SOIL_load_image(fileName,&width,&height,0,SOIL_LOAD_RGBA);                      // loads texture

    if(!image)
        std::cout << "No Image Found!" << std::endl;

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,image);    // Loads image into bucket
    SOIL_free_image_data(image);                                                            // Deletes image from variable

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);                        //
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);                        //

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);                     //
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);                     //
}

void textureLoader::binder(GLuint tId)
{
    glBindTexture(GL_TEXTURE_2D,tId);

}
