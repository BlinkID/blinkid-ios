//
//  PPResultPageViewController.m
//  BlinkInput
//
//  Created by Jura on 18/09/16.
//  Copyright © 2016 MicroBlink. All rights reserved.
//

#import "PPResultPageViewController.h"
#import "PPResultImageViewController.h"

#import "PPScanElement.h"

@interface PPResultPageViewController () <UIPageViewControllerDataSource, UIPageViewControllerDelegate>

@property (nonatomic) UIPageViewController *pageViewController;

@end

@implementation PPResultPageViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Create page view controller
    self.pageViewController = [[UIPageViewController alloc] initWithTransitionStyle:UIPageViewControllerTransitionStyleScroll
                                                              navigationOrientation:UIPageViewControllerNavigationOrientationHorizontal
                                                                            options:nil];
    self.pageViewController.dataSource = self;
    self.pageViewController.delegate = self;

    PPResultImageViewController *initialVC = [self viewControllerAtIndex:0];
    [self.pageViewController setViewControllers:@[ initialVC ]
                                      direction:UIPageViewControllerNavigationDirectionForward
                                       animated:NO
                                     completion:nil];

    [self addChildViewController:self.pageViewController];
    self.pageViewController.view.frame = self.view.bounds;
    [self.view addSubview:self.pageViewController.view];
    [self.pageViewController didMoveToParentViewController:self];

    self.title = ((PPScanElement *)[self.scanElements objectAtIndex:0]).localizedTitle;

    UIPageControl *pageControl = [UIPageControl appearanceWhenContainedIn:[PPResultPageViewController class], nil];
    pageControl.backgroundColor = [UIColor blackColor];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

    [self.navigationController setNavigationBarHidden:NO animated:animated];
}

#pragma mark - Instantiation

+ (instancetype)allocFromStoryboard {

    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"VinResult" bundle:nil];
    PPResultPageViewController *vc =
        (PPResultPageViewController *)[storyboard instantiateViewControllerWithIdentifier:@"PPResultPageViewController"];

    return vc;
}

#pragma mark - UIPageViewControllerDataSource

- (UIViewController *)pageViewController:(UIPageViewController *)pageViewController
      viewControllerBeforeViewController:(UIViewController *)viewController {

    PPResultImageViewController *imageViewController = (PPResultImageViewController *)viewController;

    if (imageViewController.pageIndex == 0) {
        return nil;
    }

    return [self viewControllerAtIndex:imageViewController.pageIndex - 1];
}

- (UIViewController *)pageViewController:(UIPageViewController *)pageViewController
       viewControllerAfterViewController:(UIViewController *)viewController {

    PPResultImageViewController *imageViewController = (PPResultImageViewController *)viewController;

    if (imageViewController.pageIndex >= self.scanElements.count - 1) {
        return nil;
    }

    return [self viewControllerAtIndex:imageViewController.pageIndex + 1];
}

- (NSInteger)presentationCountForPageViewController:(UIPageViewController *)pageViewController {
    return self.scanElements.count;
}

- (NSInteger)presentationIndexForPageViewController:(UIPageViewController *)pageViewController {
    return 0;
}

- (PPResultImageViewController *)viewControllerAtIndex:(NSUInteger)index {

    if (([self.scanElements count] == 0) || (index >= [self.scanElements count])) {
        return nil;
    }

    PPScanElement *element = (PPScanElement *)[self.scanElements objectAtIndex:index];

    // Create a new view controller and pass suitable data.
    PPResultImageViewController *resultImageViewController = [PPResultImageViewController allocFromStoryboard];

    resultImageViewController.text = element.value;
    resultImageViewController.image = element.image;
    resultImageViewController.pageIndex = index;

    return resultImageViewController;
}

#pragma mark - UIPageViewControllerDelegate

- (void)pageViewController:(UIPageViewController *)pageViewController
         didFinishAnimating:(BOOL)finished
    previousViewControllers:(NSArray<UIViewController *> *)previousViewControllers
        transitionCompleted:(BOOL)completed {

    UIViewController *viewController = [pageViewController.viewControllers lastObject];
    PPResultImageViewController *imageViewController = (PPResultImageViewController *)viewController;

    self.title = ((PPScanElement *)[self.scanElements objectAtIndex:imageViewController.pageIndex]).localizedTitle;
}


@end
