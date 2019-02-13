#ifndef DRIVEDATA_H
#define DRIVEDATA_H

#include <QString>
#include "Drives/driveenums.h"

namespace Drives
{
    ///Class which contains data about same drive
    class DriveData
    {
    private:
        ///ID of drive
        std::size_t _id = 0;
        ///Name of drive: distributor + model
        QString _driveName;
        ///Serial number of drive
        QString _serialNumber;
        ///Size drive in bytes
        long long _driveSize = 0;
        ///Size of cashe in bytes
        long _casheSize = 0;
        ///Type of bus for this drive
        EDriveBus _typeBus = EDriveBus::Error;
        ///Is this drive get data correctly?
        bool _isGood = false;
    public:
        ///Default CTOR is removed
        DriveData(void) = delete;
        explicit DriveData(std::size_t id);

        ///CTOR of copy
        DriveData(const DriveData& _val);
        ///CTOR of replace
        DriveData(DriveData&& _val);

        ///Operator of copy
        DriveData& operator= (const DriveData& _val);
        ///Operator of replace
        DriveData& operator= (DriveData&& _val);

        ///Returns ID of drive
        std::size_t GetId(void) const;
        ///Returns vendor and model of drive
        const QString& GetDriveName(void) const;
        ///Returns serial number of drive
        const QString& GetSerialNumber(void) const;
        ///Returns size of drive in bytes
        long long GetDriveSizeBytes(void) const;
        ///Returns size of cashe in bytes
        long GetCasheSizeBytes(void) const;
        ///Returns type of bus
        EDriveBus GetTypeOfBus(void) const;
        ///Is correctly get data about drive?
        ///If returns "false" - it may be means as such as "Drive isn't exists"
        bool IsGood(void)const;

        ///Default DTOR
        ~DriveData(void) = default;
    };
}
#endif // DRIVEDATA_H
