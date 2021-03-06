//
//  SUPWebViewController.h
//  SuperProject
//
//  Created by NShunJian on 2018/1/20.
//  Copyright © 2018年 superMan. All rights reserved.
//

#import "SUPBaseViewController.h"
#import <WebKit/WebKit.h>

@class SUPWebViewController;
@protocol SUPWebViewControllerDelegate <NSObject>

@optional
// 左上边的返回按钮点击
- (void)backBtnClick:(UIButton *)backBtn webView:(WKWebView *)webView ;

//左上边的关闭按钮的点击
- (void)closeBtnClick:(UIButton *)closeBtn webView:(WKWebView *)webView;

// 监听 self.webView.scrollView 的 contentSize 属性改变，从而对底部添加的自定义 View 进行位置调整
- (void)webView:(WKWebView *)webView scrollView:(UIScrollView *)scrollView contentSize:(CGSize)contentSize;

@end


@protocol SUPWebViewControllerDataSource <NSObject>

@optional
// 默认需要, 是否需要进度条
- (BOOL)webViewController:(SUPWebViewController *)webViewController webViewIsNeedProgressIndicator:(WKWebView *)webView;

// 默认需要自动改变标题
- (BOOL)webViewController:(SUPWebViewController *)webViewController webViewIsNeedAutoTitle:(WKWebView *)webView;

@end

@interface SUPWebViewController : SUPBaseViewController<WKNavigationDelegate, WKUIDelegate, SUPWebViewControllerDelegate, SUPWebViewControllerDataSource>

/** webView */
@property (nonatomic, strong) WKWebView *webView;

/** <#digest#> */
@property (nonatomic, copy) NSString *gotoURL;


// 7页面加载完调用, 必须调用super
- (void)webView:(WKWebView *)webView didFinishNavigation:(WKNavigation *)navigation NS_REQUIRES_SUPER;


// 8页面加载失败时调用, 必须调用super
- (void)webView:(WKWebView *)webView didFailProvisionalNavigation:(WKNavigation *)navigation withError:(NSError *)error NS_REQUIRES_SUPER;

@end
