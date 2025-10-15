//
// Created by jalr on 15-10-2025.
//
#ifndef SDLTEST_TEXTURE_H
#define SDLTEST_TEXTURE_H
#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <memory>
class Texture {
public:
       void LoadFromFile(const std::string& path, SDL_Renderer* renderer) {
           if (texture) {
               std::cout << "Texture from file: " << file_path << " has already been loaded" << std::endl;
           } else {
               if (SDL_Surface *loaded_surface = IMG_Load(path.c_str()); loaded_surface == nullptr) {
                   std::cout << "IMG_Load failed" << std::endl;
               } else {
                   if (texture = SDL_CreateTextureFromSurface(renderer, loaded_surface); texture == nullptr) {
                       std::cout << "SDL_CreateTextureFromSurface failed" << std::endl;
                   } else {
                       width = loaded_surface->w;
                       height = loaded_surface->h;
                   }
                   SDL_DestroySurface(loaded_surface);
               }
           }
       }
    SDL_Texture* texture = nullptr;
    std::string file_path;
    int width;
    int height;
};

#endif //SDLTEST_TEXTURE_H