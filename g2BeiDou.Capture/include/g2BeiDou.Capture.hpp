#ifdef G2BEIDOU_CAPTURE_EXPORTS
#define G2BEIDOU_CAPTURE_API __declspec(dllexport)
#else
#define G2BEIDOU_CAPTURE_API __declspec(dllimport)
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


// This class is exported from the g2BeiDou.Capture.dll
namespace cv
{
    class Mat;
}
namespace g2
{
    
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
    
    G2API Capture *CreateCapture(CaptureType mode = CaptureType::WindowHandle);
    
    G2API void DestroyCapture(Capture *&capture);
    
    G2API void SetWindowHandle(Capture *capture, CaptureOptions &options);
    
    G2API void SetDirectHandle(Capture *capture, CaptureOptions &options);
    
    G2API void SetVideoPath(Capture *capture, CaptureOptions &options);
    
    G2API void UseWindowHandleCapture(Capture *capture);
    
    G2API void UseDirectShowCapture(Capture *capture);
    
    G2API void UseVideoCapture(Capture *capture);
    
    G2API void UseVideoCapture2(Capture *capture);
    
    G2API void UseVideoCapture3(Capture *capture);
    
    G2API cv::Mat *CaptureImage(Capture *capture);
    
    G2API void ReleaseImage(cv::Mat *&image);

}
//#define DEF_Enable_WindowHandleCapture
//#define DEF_Enable_DirectShowCapture
//#define DEF_Enable_VideoCapture
//#define DEF_Enable_VideoCapture2
//#define DEF_Enable_VideoCapture3