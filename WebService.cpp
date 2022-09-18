
#include "WebService.h"
	
#ifdef DEBUG
#ifndef p(v)
// add methods and vars here for debug only
#define p(v) Serial.println(v); 
#endif
#else
// redefine the above macros, but they dont do anything
#define p(v)
#endif

	AsyncCallbackWebHandler& WebService::Add(const char* uri, ArRequestHandlerFunction onRequest)
	{
		return Server.on(uri, onRequest);
	}
	
	AsyncCallbackWebHandler& WebService::Add(const char* uri, WebRequestMethodComposite method, ArRequestHandlerFunction onRequest)
	{
		return Server.on(uri, method, onRequest);
	}
	
	AsyncCallbackWebHandler& WebService::Add(const char* uri, WebRequestMethodComposite method, ArRequestHandlerFunction onRequest, ArUploadHandlerFunction onUpload)
	{
		return Server.on(uri, method, onRequest, onUpload);
	}
	
	AsyncCallbackWebHandler& WebService::Add(const char* uri, WebRequestMethodComposite method, ArRequestHandlerFunction onRequest, ArUploadHandlerFunction onUpload, ArBodyHandlerFunction onBody)
	{
		return Server.on(uri, method, onRequest, onUpload, onBody);
	}

  void WebService::Begin()
  {
    p("Starting web service");
		DefaultHeaders::Instance().addHeader(F("Access-Control-Allow-Origin"), F("*"));
		DefaultHeaders::Instance().addHeader(F("Access-Control-Allow-Headers"), F("content-type"));
		Server.begin();  
  }

AsyncWebServer WebService::Server(80);
