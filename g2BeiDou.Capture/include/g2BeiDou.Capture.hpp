#ifdef USED_G2BEIDOU_STATICLIB
#define _LIB
#endif
#ifndef _LIB
#ifdef G2BEIDOU_CAPTURE_EXPORTS
#define G2BEIDOU_CAPTURE_API __declspec(dllexport)
#else
#define G2BEIDOU_CAPTURE_API __declspec(dllimport)
#endif
#else
#define G2BEIDOU_CAPTURE_API
#endif

#define G2API G2BEIDOU_CAPTURE_API

#ifdef Def_Enable_WindowHandle
#define DEF_Enable_WindowHandleCapture
#endif
#ifdef Def_Enable_DirectShow
#define DEF_Enable_DirectShowCapture
#endif
#ifdef Def_Enable_Video
#define DEF_Enable_VideoCapture
#endif
#ifdef Def_Enable_Video2
#define DEF_Enable_VideoCapture2
#endif
#ifdef Def_Enable_Video3
#define DEF_Enable_VideoCapture3
#endif

#ifndef Def_Build_CPP_INTERFACE
namespace cv
{
    class Mat;
}
#else
#include <opencv2/core.hpp>
#endif

// This class is exported from the g2BeiDou.Capture.dll
namespace g2
{
    struct err{
        int code;
        const char* message;
        const char* name;
    };
    
    class CaptureException;
    enum CaptureType
    {
        WindowHandle,
        DirectShow,
        Video,
        Video2,
        Video3,
    };
    
    class CaptureOptions
    {
    public:
        CaptureOptions() = default;
        ~CaptureOptions() = default;
    public:
        long long int window_handle = 0;
        long long int direct_handle = 0;
        char *video_path = nullptr;
    };
    class Capture;

    extern "C" {
    
        G2API Capture *CreateCapture(CaptureType mode = CaptureType::WindowHandle);
        
        G2API void DestroyCapture(Capture *&capture);
        
        G2API void SetWindowHandle(Capture *capture,const CaptureOptions &options);
        
        G2API void SetDirectHandle(Capture *capture,const CaptureOptions &options);
        
        G2API void SetVideoPath(Capture *capture,const CaptureOptions &options);
        
        G2API void UseWindowHandleCapture(Capture *capture);
        
        G2API void UseDirectShowCapture(Capture *capture);
        
        G2API void UseVideoCapture(Capture *capture);
        
        G2API void UseVideoCapture2(Capture *capture);
        
        G2API void UseVideoCapture3(Capture *capture);
        
        G2API cv::Mat *CaptureImage(Capture *capture);
        
        G2API void ReleaseImage(cv::Mat *&image);
    };

#ifdef Def_Build_CPP_INTERFACE
    class G2API CaptureManager
    {
        Capture* capture = nullptr;
        CaptureType mode = CaptureType::WindowHandle;
        CaptureOptions options;
    public:
        explicit CaptureManager(CaptureType mode = CaptureType::WindowHandle);
        CaptureManager(CaptureType mode,const CaptureOptions &options);
        
        ~CaptureManager();
        
        void reinitialize(CaptureType mode);
        void set(const CaptureOptions &options);
        
        cv::Mat get();
        
        err get_last_error();
    };
#endif
}
#define DEF_Enable_WindowHandleCapture
#define DEF_Enable_DirectShowCapture
//#define DEF_Enable_VideoCapture
//#define DEF_Enable_VideoCapture2
//#define DEF_Enable_VideoCapture3