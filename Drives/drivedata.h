#pragma once
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
        explicit DriveData(std::size_t id)
        {
            ///Сюда нужно поместить код инициализации
            this->_id = id;
        }

        ///CTOR of copy
        DriveData(const DriveData& _val)
        {
            this->_id = _val.GetId();
            this->_driveName = _val.GetDriveName();
            this->_serialNumber = _val.GetSerialNumber();
            this->_driveSize = _val.GetDriveSizeBytes();
            this->_casheSize = _val.GetCasheSizeBytes();
            this->_typeBus = _val.GetTypeOfBus();
            this->_isGood = _val.IsGood();
        }
        ///CTOR of replace
        DriveData(DriveData&& _val)
        {
            this->_id = _val.GetId();
            this->_driveName = _val.GetDriveName();
            this->_serialNumber = _val.GetSerialNumber();
            this->_driveSize = _val.GetDriveSizeBytes();
            this->_casheSize = _val.GetCasheSizeBytes();
            this->_typeBus = _val.GetTypeOfBus();
            this->_isGood = _val.IsGood();

            _val._id = NULL;
            _val._driveName = "";
            _val._serialNumber = "";
            _val._driveSize = NULL;
            _val._casheSize = NULL;
            _val._typeBus = EDriveBus::Error;
            _val._isGood = false;
        }

        ///Operator of copy
        DriveData& operator= (const DriveData& _val)
        {
            this->_id = _val.GetId();
            this->_driveName = _val.GetDriveName();
            this->_serialNumber = _val.GetSerialNumber();
            this->_driveSize = _val.GetDriveSizeBytes();
            this->_casheSize = _val.GetCasheSizeBytes();
            this->_typeBus = _val.GetTypeOfBus();
            this->_isGood = _val.IsGood();

            return *this;
        }
        ///Operator of replace
        DriveData& operator= (DriveData&& _val)
        {
            this->_id = _val.GetId();
            this->_driveName = _val.GetDriveName();
            this->_serialNumber = _val.GetSerialNumber();
            this->_driveSize = _val.GetDriveSizeBytes();
            this->_casheSize = _val.GetCasheSizeBytes();
            this->_typeBus = _val.GetTypeOfBus();
            this->_isGood = _val.IsGood();

            _val._id = NULL;
            _val._driveName = "";
            _val._serialNumber = "";
            _val._driveSize = NULL;
            _val._casheSize = NULL;
            _val._typeBus = EDriveBus::Error;
            _val._isGood = false;

            return *this;
        }

        ///Returns ID of drive
        std::size_t GetId(void) const
        {
            return this->_id;
        }
        ///Returns vendor and model of drive
        const QString& GetDriveName(void) const
        {
            return this->_driveName;
        }
        ///Returns serial number of drive
        const QString& GetSerialNumber(void) const
        {
            return this->_serialNumber;
        }
        ///Returns size of drive in bytes
        long long GetDriveSizeBytes(void) const
        {
            return this->_driveSize;
        }
        ///Returns size of cashe in bytes
        long GetCasheSizeBytes(void) const
        {
            return this->_casheSize;
        }
        ///Returns type of bus
        EDriveBus GetTypeOfBus(void) const
        {
            return this->_typeBus;
        }
        ///Is correctly get data about drive?
        ///If returns "false" - it may be means as such as "Drive isn't exists"
        bool IsGood(void)const
        {
            return this->_isGood;
        }

        ///Default DTOR
        ~DriveData(void) = default;
    };
}
