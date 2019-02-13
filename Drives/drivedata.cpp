#include "drivedata.h"

namespace Drives
{
    DriveData::DriveData(std::size_t id)
    {
        ///Сюда нужно поместить код инициализации
        this->_id = id;

    }

    DriveData::DriveData(const DriveData& _val)
    {
        this->_id = _val.GetId();
        this->_driveName = _val.GetDriveName();
        this->_serialNumber = _val.GetSerialNumber();
        this->_driveSize = _val.GetDriveSizeBytes();
        this->_casheSize = _val.GetCasheSizeBytes();
        this->_typeBus = _val.GetTypeOfBus();
        this->_isGood = _val.IsGood();
    }
    DriveData::DriveData(DriveData&& _val)
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

    DriveData& DriveData::operator= (const DriveData& _val)
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
    DriveData& DriveData::operator= (DriveData&& _val)
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

    std::size_t DriveData::GetId(void) const
    {
        return this->_id;
    }
    const QString& DriveData::GetDriveName(void) const
    {
        return this->_driveName;
    }
    const QString& DriveData::GetSerialNumber(void) const
    {
        return this->_serialNumber;
    }
    long long DriveData::GetDriveSizeBytes(void) const
    {
        return this->_driveSize;
    }
    long DriveData::GetCasheSizeBytes(void) const
    {
        return this->_casheSize;
    }
    EDriveBus DriveData::GetTypeOfBus(void) const
    {
        return this->_typeBus;
    }
    bool DriveData::IsGood(void) const
    {
        return this->_isGood;
    }
}
