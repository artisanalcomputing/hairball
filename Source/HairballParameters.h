/*
  ==============================================================================

    HairballParameters.h
    Created: 24 May 2019 11:25:40am
    Author:  accraze

  ==============================================================================
*/

#pragma once

enum HairballParameter
{
    hParameter_Drive = 0,
    hParameter_Range,
    hParameter_Blend,
    hParameter_Volume,
    hParameter_TotalNumParameters,
};

static String HairballParameterLabel [hParameter_TotalNumParameters] =
{
    "Drive",
    "Range",
    "Blend",
    "Volume"
};

static String HairballParameterID [hParameter_TotalNumParameters] =
{
    "drive",
    "range",
    "blend",
    "volume"
};

static NormalisableRange<float> HairballParameterRange [hParameter_TotalNumParameters] =
{
    NormalisableRange<float>(0.0f, 1.0f),
    NormalisableRange<float>(0.f, 3000.f),
    NormalisableRange<float>(0.f, 1.f),
    NormalisableRange<float>(0.f, 3.f),
};

static float HairballParameterDefaultValue [hParameter_TotalNumParameters] =
{
    0.5f,
    0.5f,
    0.5f,
    0.5f
};
