#include "g2BeiDou.Capture.hpp"

#include <opencv2/opencv.hpp>

#ifdef DEF_Enable_WindowHandleCapture
#include "window/WindowHandleCapture.h"
#endif
#ifdef DEF_Enable_DirectShowCapture
#include "window/DirectShowCapture.h"
#endif
#ifdef DEF_Enable_VideoCapture
#include "video/VideoCapture.h"
#endif

namespace g2
{
    class CaptureException : public std::exception
    {
    public:
        CaptureException(int _code, const std::string& _err, const std::string& _func, const std::string& _file, int _line)
                : code(_code), err(_err), func(_func), file(_file), line(_line) {
            formatMessage();
        }
        ~CaptureException() throw() {};
        
        const char *what() const throw() override {
            return err.c_str();
        }
        void formatMessage() {
            std::stringstream ss;
            ss << "CaptureException: " << err << " in " << func << " at " << file << ":" << line;
            err = ss.str();
        }
        
        std::string msg; ///< the formatted error message
        
        int code; ///< error code
        std::string err; ///< error description
        std::string func; ///< function name. Available only when the compiler supports getting it
        std::string file; ///< source file name where the error has occurred
        int line; ///< line number in the source file where the error has occurred
    };
    
    std::vector<CaptureType> GetAvailableCaptureTypes()
    {
        std::vector<CaptureType> capture_types;
#ifdef DEF_Enable_WindowHandleCapture
        capture_types.push_back(CaptureType::WindowHandle);
#endif
#ifdef DEF_Enable_DirectShowCapture
        capture_types.push_back(CaptureType::DirectShow);
#endif
#ifdef DEF_Enable_VideoCapture
        capture_types.push_back(CaptureType::Video);
#endif
#ifdef DEF_Enable_VideoCapture2
        capture_types.push_back(CaptureType::Video2);
#endif
#ifdef DEF_Enable_VideoCapture3
        capture_types.push_back(CaptureType::Video3);
#endif
        return capture_types;
    }
    
    Capture* CreateWindowHandle() {
#ifdef DEF_Enable_WindowHandleCapture
        return new WindowHandleCapture();
#else
        throw CaptureException(0, "Don't Create WindowHandleCapture ,it's not enabled", __FUNCTION__, __FILE__, __LINE__);
#endif
    }
    Capture* CreateDirectShow() {
#ifdef DEF_Enable_DirectShowCapture
        return new DirectShowCapture();
#else
        throw CaptureException(0, "Don't Create DirectShowCapture ,it's not enabled", __FUNCTION__, __FILE__, __LINE__);
#endif
    }
    Capture* CreateVideo() {
#ifdef DEF_Enable_VideoCapture
        return new VideoCapture();
#else
        throw CaptureException(0, "Don't Create VideoCapture ,it's not enabled", __FUNCTION__, __FILE__, __LINE__);
#endif
    }
    Capture* CreateVideo2() {
#ifdef DEF_Enable_VideoCapture2
        return new VideoCapture2();
#else
        throw CaptureException(0, "Don't Create VideoCapture2 ,it's not enabled", __FUNCTION__, __FILE__, __LINE__);
#endif
    }
    Capture* CreateVideo3() {
#ifdef DEF_Enable_VideoCapture3
        return new VideoCapture3();
#else
        throw CaptureException(0, "Don't Create VideoCapture3 ,it's not enabled", __FUNCTION__, __FILE__, __LINE__);
#endif
    }
    
    Capture *CreateCapture(CaptureType mode) {
        switch (mode) {
            case CaptureType::WindowHandle:
                return CreateWindowHandle();
            case CaptureType::DirectShow:
                return CreateDirectShow();
            case CaptureType::Video:
                return CreateVideo();
            case CaptureType::Video2:
                return CreateVideo2();
            case CaptureType::Video3:
                return CreateVideo3();
            default:
                return nullptr;
        }
    }
    void DestroyCapture(Capture *&capture) {
        delete capture;
        capture = nullptr;
    }
    
    void SetWindowHandle(Capture* capture,const CaptureOptions& options){
#ifdef DEF_Enable_WindowHandleCapture
        WindowHandleCapture* window_handle_capture = dynamic_cast<WindowHandleCapture*>(capture);
        if (window_handle_capture != nullptr) {
            window_handle_capture->reinitialize((HWND)options.window_handle);
        }
        else
        {
            throw CaptureException(0, "capture is not WindowHandleCapture", __FUNCTION__, __FILE__, __LINE__);
        }
#else
        throw CaptureException(0, "WindowHandleCapture is not enabled", __FUNCTION__, __FILE__, __LINE__);
#endif
    }
    void SetDirectHandle(Capture* capture,const CaptureOptions& options){
#ifdef DEF_Enable_DirectShowCapture
        DirectShowCapture* direct_show_capture = dynamic_cast<DirectShowCapture*>(capture);
        if (direct_show_capture != nullptr) {
            HWND handle = (HWND)options.direct_handle;
            direct_show_capture->reinitialize(handle);
        }
        else
        {
            throw CaptureException(0, "capture is not DirectShowCapture", __FUNCTION__, __FILE__, __LINE__);
        }
#else
        throw CaptureException(0, "DirectShowCapture is not enabled", __FUNCTION__, __FILE__, __LINE__);
#endif
    }
    void SetVideoPath(Capture* capture,const CaptureOptions& options){
#ifdef DEF_Enable_VideoCapture
        VideoCapture* video_capture = dynamic_cast<VideoCapture*>(capture);
        if (video_capture != nullptr) {
            video_capture->reinitialize(options.video_path);
        }
        else
        {
            throw CaptureException(0, "capture is not VideoCapture", __FUNCTION__, __FILE__, __LINE__);
        }
#else
        throw CaptureException(0, "VideoCapture is not enabled", __FUNCTION__, __FILE__, __LINE__);
#endif
    }
    
    void UseWindowHandleCapture(Capture *capture) {
#ifdef DEF_Enable_WindowHandleCapture
        //TODO: check capture type
        //capture->UseWindowHandleCapture();
#else
        throw CaptureException(0, "The Capture didn't compile with WindowHandle Inference.", __FUNCTION__, __FILE__, __LINE__);
#endif
    }
    void UseDirectShowCapture(Capture *capture) {
#ifdef DEF_Enable_DirectShowCapture
        //TODO: check capture type
        //capture->UseDirectShowCapture();
#else
        throw CaptureException(0, "The Capture didn't compile with DirectShow Inference.", __FUNCTION__, __FILE__, __LINE__);
#endif
    }
    void UseVideoCapture(Capture *capture) {
#ifdef DEF_Enable_VideoCapture
        //TODO: check if the capture is VideoCapture
        //capture->UseVideoCapture();
#else
        throw CaptureException(0, "The Capture didn't compile with VideoCapture Inference.", __FUNCTION__, __FILE__, __LINE__);
#endif
    }
    void UseVideoCapture2(Capture *capture) {
#ifdef DEF_Enable_VideoCapture2
        capture->UseVideoCapture2();
#else
        throw CaptureException(0, "The Capture didn't compile with VideoCapture2 Inference.", __FUNCTION__, __FILE__, __LINE__);
#endif
    }
    void UseVideoCapture3(Capture *capture) {
#ifdef DEF_Enable_VideoCapture3
        capture->UseVideoCapture3();
#else
        throw CaptureException(0, "The Capture didn't compile with VideoCapture3 Inference.", __FUNCTION__, __FILE__,
                               __LINE__);
#endif
    }

    cv::Mat* CaptureImage(Capture *capture){
        auto *image= new cv::Mat();
        *image = capture->get();
        return image;
    }
    
    void ReleaseImage(cv::Mat *&image){
        delete image;
        image = nullptr;
    }
#ifdef __cplusplus
    CaptureManager::CaptureManager(CaptureType mode):mode(mode) {
        capture = CreateCapture(this->mode);
        set(this->options);
        capture->initialize();
    }
    CaptureManager::CaptureManager(CaptureType mode, const CaptureOptions &options):mode(mode),options(options) {
        capture = CreateCapture(this->mode);
        set(this->options);
        capture->initialize();
    }
    
    CaptureManager::~CaptureManager() {
        DestroyCapture(capture);
    }
    
    void CaptureManager::set(const CaptureOptions &options) {
        switch (mode) {
            case CaptureType::WindowHandle:
                SetWindowHandle(capture, options);
                break;
            case CaptureType::DirectShow:
                SetDirectHandle(capture, options);
                break;
            case CaptureType::Video:
                SetVideoPath(capture, options);
                break;
            case CaptureType::Video2:
                SetVideoPath(capture, options);
                break;
            case CaptureType::Video3:
                SetVideoPath(capture, options);
                break;
            default:
                break;
        }
    }
    
    void CaptureManager::reinitialize(CaptureType mode) {
        this->mode = mode;
        DestroyCapture(capture);
        capture = CreateCapture(mode);
    }
    
    cv::Mat CaptureManager::get() {
        return capture->get();
    }
    
    err CaptureManager::get_last_error() {
        err e;
        e.code = capture->error.code;
        e.message = capture->error.message.c_str();
        
        return e;
    }

#endif
}