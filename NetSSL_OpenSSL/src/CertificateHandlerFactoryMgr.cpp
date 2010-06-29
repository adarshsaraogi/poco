//
// CertificateHandlerFactoryMgr.cpp
//
// $Id: //poco/1.3/NetSSL_OpenSSL/src/CertificateHandlerFactoryMgr.cpp#4 $
//
// Library: NetSSL_OpenSSL
// Package: SSLCore
// Module:  CertificateHandlerFactoryMgr
//
// Copyright (c) 2006-2009, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "Poco/Net/CertificateHandlerFactoryMgr.h"
#include "Poco/Net/ConsoleCertificateHandler.h"
#include "Poco/Net/AcceptCertificateHandler.h"
#include "Poco/Net/RejectCertificateHandler.h"


namespace Poco {
namespace Net {


CertificateHandlerFactoryMgr::CertificateHandlerFactoryMgr()
{
	setFactory("ConsoleCertificateHandler", new CertificateHandlerFactoryImpl<ConsoleCertificateHandler>());
	setFactory("AcceptCertificateHandler", new CertificateHandlerFactoryImpl<AcceptCertificateHandler>());
	setFactory("RejectCertificateHandler", new CertificateHandlerFactoryImpl<RejectCertificateHandler>());
}


CertificateHandlerFactoryMgr::~CertificateHandlerFactoryMgr()
{
}


void CertificateHandlerFactoryMgr::setFactory(const std::string& name, CertificateHandlerFactory* pFactory)
{
	bool success = _factories.insert(make_pair(name, Poco::SharedPtr<CertificateHandlerFactory>(pFactory))).second;
	if (!success)
		delete pFactory;
	poco_assert(success);
}
		

bool CertificateHandlerFactoryMgr::hasFactory(const std::string& name) const
{
	return _factories.find(name) != _factories.end();
}
		
	
const CertificateHandlerFactory* CertificateHandlerFactoryMgr::getFactory(const std::string& name) const
{
	FactoriesMap::const_iterator it = _factories.find(name);
	if (it != _factories.end())
		return it->second;
	else
		return 0;
}


void CertificateHandlerFactoryMgr::removeFactory(const std::string& name)
{
	_factories.erase(name);
}


} } // namespace Poco::Net
