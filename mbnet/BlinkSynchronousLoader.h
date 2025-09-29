//
// Copyright (c) 2025 Institute of Software, Chinese Academy of Sciences (ISCAS)
// LiteView is licensed under Mulan PSL v2.
// You can use this software according to the terms and conditions of the Mulan PSL v2.
// You may obtain a copy of Mulan PSL v2 at:
//          http://license.coscl.org.cn/MulanPSL2
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
// EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
// MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
// See the Mulan PSL v2 for more details.
//


namespace net {

class BlinkSynchronousLoader : public blink::WebURLLoaderClient {
    WTF_MAKE_NONCOPYABLE(BlinkSynchronousLoader);
public:
    BlinkSynchronousLoader(blink::WebURLError&, blink::WebURLResponse&, Vector<char>&);
    ~BlinkSynchronousLoader();

    virtual void didReceiveResponse(blink::WebURLLoader*, const blink::WebURLResponse&);
    virtual void didReceiveData(blink::WebURLLoader*, const char* data, int dataLength, int encodedDataLength);
    virtual void didFinishLoading(blink::WebURLLoader* loader, double finishTime, int64_t totalEncodedDataLength);
    virtual void didFail(blink::WebURLLoader*, const blink::WebURLError&);

private:
    blink::WebURLError& m_error;
    blink::WebURLResponse& m_response;
    Vector<char>& m_data;
};

inline BlinkSynchronousLoader::BlinkSynchronousLoader(blink::WebURLError& error, blink::WebURLResponse& response, Vector<char>& data)
    : m_error(error)
    , m_response(response)
    , m_data(data)
{
}

inline BlinkSynchronousLoader::~BlinkSynchronousLoader()
{

}

inline void BlinkSynchronousLoader::didReceiveResponse(blink::WebURLLoader*, const blink::WebURLResponse& response)
{
    m_response = response;
}

inline void BlinkSynchronousLoader::didReceiveData(blink::WebURLLoader*, const char* data, int dataLength, int encodedDataLength)
{
    m_data.append(data, dataLength);
}

inline void BlinkSynchronousLoader::didFinishLoading(blink::WebURLLoader* loader, double finishTime, int64_t totalEncodedDataLength)
{
}

inline void BlinkSynchronousLoader::didFail(blink::WebURLLoader*, const blink::WebURLError& error)
{
    m_error = error;
}

}