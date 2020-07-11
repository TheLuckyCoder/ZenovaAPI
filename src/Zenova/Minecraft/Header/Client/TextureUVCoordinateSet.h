#pragma once

#include <cstdint>

class ResourceLocation;

enum class ResourceFileSystem {
    InUserPackage,
    InAppPackage,
    RawPath,
    InSettingDir,
    InExternalDir,
    InServerPackage,
    InDataDir,
    InUserDir,
    InWorldDir
};

class IsotropicFaceData {
private:
    unsigned int mFaceTextureIsotropic;
    unsigned int mIsotropicFaceEnabled;
};

class TextureUVCoordinateSet {
private:
    float weight;
    float _u0;
    float _v0;
    float _u1;
    float _v1;
    uint16_t _texSizeW;
    uint16_t _texSizeH;
    char sourceFileLocation[0x38];
    IsotropicFaceData mIsotropicFaceData;
};