#ifndef _WEBSERVICE_
#define _WEBSERVICE_

#include <ESPAsyncWebServer.h>

class WebService
{
    static AsyncWebServer Server;
public:
	static AsyncCallbackWebHandler& Add(const char* uri, ArRequestHandlerFunction onRequest);
	static AsyncCallbackWebHandler& Add(const char* uri, WebRequestMethodComposite method, ArRequestHandlerFunction onRequest);
	static AsyncCallbackWebHandler& Add(const char* uri, WebRequestMethodComposite method, ArRequestHandlerFunction onRequest, ArUploadHandlerFunction onUpload);
	static AsyncCallbackWebHandler& Add(const char* uri, WebRequestMethodComposite method, ArRequestHandlerFunction onRequest, ArUploadHandlerFunction onUpload, ArBodyHandlerFunction onBody);

  static void Begin();
};
#endif