#pragma once
namespace Drives
{
    enum EDriveBus : char
    {
        Error,
        PATA,
        SATA_I,
        SATA_II,
        SATA_III,
        M2,
        Thunderbolt,
        mSata,
        Another
    };
}
