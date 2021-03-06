#include "imagetex.h"

namespace yy {
namespace volren {

ImageTex::ImageTex(GLuint tex)
 : ImageAbstract(TYPE_TEXTURE)
 , initialized(false)
 , tex(tex)
{

}

ImageTex::ImageTex(const ImageTex &image)
 : ImageAbstract(TYPE_TEXTURE)
 , initialized(false)
 , tex(image.tex)
{

}

ImageTex &ImageTex::operator=(const ImageTex &image)
{
    initialized = false;
    this->tex = image.tex;
    return *this;
}

ImageTex::~ImageTex()
{

}

void ImageTex::initialize()
{
    painter.initializeGL(":/volren/shaders/quad.vert", ":/volren/shaders/quad.frag");
    initialized = true;
}

void ImageTex::draw()
{
    if (!initialized)
        initialize();
    glBindTexture(GL_TEXTURE_2D, tex);
    painter.paint("tex", 0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

} // namespace volren
} // namespace yy
