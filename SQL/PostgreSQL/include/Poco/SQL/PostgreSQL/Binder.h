//
// Binder.h
//
// Library: Data/PostgreSQL
// Package: PostgreSQL
// Module:  Binder
//
// Definition of the Binder class.
//
// Copyright (c) 2015, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef SQL_PostgreSQL_Binder_INCLUDED
#define SQL_PostgreSQL_Binder_INCLUDED

#include "Poco/SQL/PostgreSQL/PostgreSQL.h"
#include "Poco/SQL/PostgreSQL/PostgreSQLTypes.h"
#include "Poco/SQL/PostgreSQL/PostgreSQLException.h"

#include "Poco/SQL/AbstractBinder.h"
#include "Poco/SQL/Binding.h"
#include "Poco/SQL/MetaColumn.h"
#include "Poco/SQL/LOB.h"
#include "Poco/Types.h"

#include <libpq-fe.h>

namespace Poco {
namespace SQL {
namespace PostgreSQL {


class PostgreSQL_API Binder: public Poco::SQL::AbstractBinder
	/// Binds INPUT (only) placeholders in the sql query to the provided values.
	/// Allows data type mapping at statement execution time.
{
public:
	typedef SharedPtr<Binder> Ptr;

	Binder();
		/// Creates the Binder.
		
	virtual ~Binder();
		/// Destroys the Binder.

	virtual void bind(std::size_t pos, const Poco::Int8& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds an Int8.

	virtual void bind(std::size_t pos, const Poco::UInt8& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds an UInt8.

	virtual void bind(std::size_t pos, const Poco::Int16& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds an Int16.

	virtual void bind(std::size_t pos, const Poco::UInt16& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds an UInt16.

	virtual void bind(std::size_t pos, const Poco::Int32& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds an Int32.

	virtual void bind(std::size_t pos, const Poco::UInt32& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds an UInt32.

	virtual void bind(std::size_t pos, const Poco::Int64& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds an Int64.

	virtual void bind(std::size_t pos, const Poco::UInt64& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds an UInt64.

#ifndef POCO_LONG_IS_64_BIT

	virtual void bind(std::size_t pos, const long& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds a long.

	virtual void bind(std::size_t pos, const unsigned long& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds an unsigned long.

#endif // POCO_LONG_IS_64_BIT

	virtual void bind(std::size_t pos, const bool& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds a boolean.

	virtual void bind(std::size_t pos, const float& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds a float.

	virtual void bind(std::size_t pos, const double& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds a double.

	virtual void bind(std::size_t pos, const char& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds a single character.

	virtual void bind(std::size_t pos, const std::string& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds a string.

	virtual void bind(std::size_t pos, const Poco::SQL::BLOB& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds a BLOB.

	virtual void bind(std::size_t pos, const Poco::SQL::CLOB& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds a CLOB.

	virtual void bind(std::size_t pos, const DateTime& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds a DateTime.

	virtual void bind(std::size_t pos, const Date& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds a Date.

	virtual void bind(std::size_t pos, const Time& val, Direction dir = PD_IN, const WhenNullCb& nullCb = WhenNullCb());
		/// Binds a Time.

	virtual void bind(std::size_t pos, const NullData& val, Direction dir = PD_IN, const std::type_info& bindType = typeid(void));
		/// Binds a null.


	virtual void bind(std::size_t pos, const std::vector<Poco::Int8>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<Poco::Int8>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<Poco::Int8>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<Poco::UInt8>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<Poco::UInt8>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<Poco::UInt8>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<Poco::Int16>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<Poco::Int16>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<Poco::Int16>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<Poco::UInt16>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<Poco::UInt16>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<Poco::UInt16>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<Poco::Int32>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<Poco::Int32>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<Poco::Int32>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<Poco::UInt32>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<Poco::UInt32>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<Poco::UInt32>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<Poco::Int64>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<Poco::Int64>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<Poco::Int64>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<Poco::UInt64>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<Poco::UInt64>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<Poco::UInt64>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<bool>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<bool>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<bool>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<float>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<float>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<float>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<double>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<double>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<double>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<char>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<char>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<char>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<BLOB>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<BLOB>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<BLOB>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<CLOB>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<CLOB>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<CLOB>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<DateTime>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<DateTime>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<DateTime>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<Date>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<Date>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<Date>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<Time>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<Time>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<Time>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::vector<NullData>& val, Direction dir = PD_IN, const std::type_info& bindType = typeid(void));

	virtual void bind(std::size_t pos, const std::deque<NullData>& val, Direction dir = PD_IN, const std::type_info& bindType = typeid(void));

	virtual void bind(std::size_t pos, const std::list<NullData>& val, Direction dir = PD_IN, const std::type_info& bindType = typeid(void));

	virtual void bind(std::size_t pos, const std::vector<std::string>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::deque<std::string>& val, Direction dir = PD_IN);

	virtual void bind(std::size_t pos, const std::list<std::string>& val, Direction dir = PD_IN);

	template <class T>
	void bind(std::size_t pos, const std::vector<T>& val, Direction dir = PD_IN)
	{
		poco_assert(dir == PD_IN);

		typename std::vector<T>::iterator first = const_cast<std::vector<T> &>(val).begin();
		typename std::vector<T>::iterator last = const_cast<std::vector<T> &>(val).end();

		realContainerBind<typename std::vector<T>::iterator, T>(pos, first, last);
	}

	template <class T>
	void bind(std::size_t pos, const std::deque<T>& val, Direction dir = PD_IN)
	{
		poco_assert(dir == PD_IN);

		typename std::deque<T>::iterator first = const_cast<std::deque<T> &>(val).begin();
		typename std::deque<T>::iterator last = const_cast<std::deque<T> &>(val).end();

		realContainerBind<typename std::deque<T>::iterator, T>(pos, first, last);
	}

	template <class T>
	void bind(std::size_t pos, const std::list<T>& val, Direction dir = PD_IN)
	{
		poco_assert(dir == PD_IN);

		typename std::list<T>::iterator first = const_cast<std::list<T> &>(val).begin();
		typename std::list<T>::iterator last = const_cast<std::list<T> &>(val).end();

		realContainerBind<typename std::list<T>::iterator, T>(pos, first, last);
	}

	std::size_t size() const;
		/// Return count of bound parameters

	InputParameterVector bindVector() const;
		/// Return the vector of bound parameters.

	void updateBindVectorToCurrentValues();
		/// obtain the current version of the bound data and update the internal representation

private:
	Binder(const Binder&);
		/// Don't copy the binder

	virtual void bind(std::size_t, const char* const&, Direction, const WhenNullCb&)
		/// Binds a const char ptr.
		/// This is a private no-op in this implementation
		/// due to security risk.
	{
	}
	
	void realBind(std::size_t aPosition, Poco::SQL::MetaColumn::ColumnDataType aFieldType, const void* aBufferPtr, std::size_t aLength);
		/// Common bind implementation

	template <class Iterator, class T>
	void realContainerBind(std::size_t pos, Iterator first, Iterator last)
	{
		try
		{
			std::string preparedString = "";
			Iterator begin = first;

			for (; first != last; ++first)
			{
				if (first != begin)
					preparedString.append(1, '\n');

				Binder::Ptr tmpBinder = new Binder();

				std::size_t pos = 0;

				AbstractBinding::Ptr tmpBind = new Binding<T>(*first);
				tmpBind->setBinder(tmpBinder);
				tmpBind->bind(pos);
				tmpBinder->updateBindVectorToCurrentValues();

				InputParameterVector params = tmpBinder->bindVector();

				InputParameterVector::const_iterator paramsIt = params.cbegin();
				InputParameterVector::const_iterator ParamsItEnd = params.cend();

				for (; paramsIt != ParamsItEnd; ++paramsIt)
				{
					if (paramsIt != params.cbegin())
						preparedString.append(1, '\t');

					preparedString.append(static_cast<const char*>(paramsIt->pInternalRepresentation()));
				}
			}

			InputParameter inputParameter(Poco::SQL::MetaColumn::FDT_STRING, nullptr, 0);
			inputParameter.setStringVersionRepresentation(preparedString);

			if (pos >= _bindVector.size())
			{
				_bindVector.resize(pos + 1);
			}

			_bindVector[pos] = inputParameter;
		}
		catch (std::bad_alloc&)
		{
			PostgreSQLException("Memory allocation error while binding");
		}
	}

private:

	InputParameterVector _bindVector;
};


} } } // namespace Poco::SQL::PostgreSQL


#endif // Data_PostgreSQL_Binder_INCLUDED
