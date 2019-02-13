#ifndef MEMORY_CUSTOM_H
#define MEMORY_CUSTOM_H

#include <QString>

namespace Utilites
{
    class Memory
    {
    private:
        ///Enum of physical size
        enum EPhysicalSize : short
        {
            NoRank,
            Kilo,
            Mega,
            Gigo,
            Terra
        };

        ///Constant expression which defines how much bytes need for next rank
        static constexpr std::size_t BYTES_STEP = 1024U;
        ///Constant expression which defines how much bibytes need for next rank
        static constexpr std::size_t BIBYTES_STEP = 1000U;

        ///Appends text of physical size
        static void AppendStepByte(QString& str, EPhysicalSize ps)
        {
            try
            {
                str.append(" ");
                switch(ps)
                {
                case EPhysicalSize::NoRank:
                    str.append("B");
                    return;
                case EPhysicalSize::Kilo:
                    str.append("KiB");
                    return;
                case EPhysicalSize::Mega:
                    str.append("MiB");
                    return;
                case EPhysicalSize::Gigo:
                    str.append("GiB");
                    return;
                case EPhysicalSize::Terra:
                    str.append("Ti B");
                    return;
                }
            }
            catch (const std::exception& ex)
            {
                throw ex;
            }
        }

    public:
        static QString BytesToShortString(long long bytes)
        {
            if (bytes < 0)
                return "ERR VAL";

            long long tmp = bytes;
            QString str;

            try
            {
                short rank = EPhysicalSize::NoRank;

                while(bytes >= Memory::BYTES_STEP
                      && rank <= EPhysicalSize::Terra)
                {
                    bytes /= Memory::BYTES_STEP;
                    ++rank;
                }

                str.append(QString::number(bytes));
                Memory::AppendStepByte(str, static_cast<EPhysicalSize>(rank));
                str.append(" ");

                if(rank != EPhysicalSize::NoRank)
                {
                    for(short low_rank = 0; low_rank < rank - 1; ++low_rank)
                        tmp /= Memory::BYTES_STEP;
                }
                tmp %= Memory::BYTES_STEP;
                if(!tmp)
                    return str;

                str.append(QString::number(tmp));
                Memory::AppendStepByte(str, static_cast<EPhysicalSize>(rank - 1));


                return str;
            }
            catch(const std::exception&)
            {
                return "ERR FNC";
            }
        }
    };
}

#endif
