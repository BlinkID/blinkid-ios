//
//  PPBlinkOcrHelpViewController.m
//  BlinkOCR-sample
//
//  Created by Jura on 10/03/15.
//  Copyright (c) 2015 MicroBlink. All rights reserved.
//

#import "PPBlinkOcrHelpPageViewController.h"

#import "PPBlinkOcrHelpPage1ViewController.h"

@interface PPBlinkOcrHelpPageViewController () <UIPageViewControllerDataSource>

@property (nonatomic, assign) NSUInteger pageIndex;

@property (nonatomic, assign) NSUInteger numPages;

@property (nonatomic, strong) NSMutableArray *pageControllers;

@end

@implementation PPBlinkOcrHelpPageViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.dataSource = self;

    self.pageIndex = 0;
    self.numPages = 3;

    self.pageControllers = [[NSMutableArray alloc] initWithCapacity:self.numPages];
    for (NSUInteger i = 0; i < self.numPages; i++) {
        [self.pageControllers addObject:[NSNull null]];
    }

    UIViewController *startingViewController = [self viewControllerAtIndex:self.pageIndex];

    [self setViewControllers:@[startingViewController] direction:UIPageViewControllerNavigationDirectionForward animated:NO completion:nil];
}

#pragma mark - UIPageViewControllerDataSource

- (UIViewController *)pageViewController:(UIPageViewController *)pageViewController
      viewControllerBeforeViewController:(UIViewController *)viewController {

    NSUInteger index = [self.pageControllers indexOfObject:viewController];

    if ((index == 0) || (index == NSNotFound)) {
        return nil;
    }

    return [self viewControllerAtIndex:index - 1];
}

- (UIViewController *)pageViewController:(UIPageViewController *)pageViewController
       viewControllerAfterViewController:(UIViewController *)viewController {

    NSUInteger index = [self.pageControllers indexOfObject:viewController];

    if (index == NSNotFound || index == self.numPages - 1) {
        return nil;
    }

    return [self viewControllerAtIndex:index + 1];
}


- (NSInteger)presentationCountForPageViewController:(UIPageViewController *)pageViewController {
    return self.numPages;
}

- (NSInteger)presentationIndexForPageViewController:(UIPageViewController *)pageViewController {
    return 0;
}

#pragma mark - Pages

- (UIViewController *)viewControllerAtIndex:(NSUInteger)index {

    if ((self.numPages == 0) || (index >= self.numPages)) {
        return nil;
    }

    if (![[NSNull null] isEqual:[self.pageControllers objectAtIndex:index]]) {
        return [self.pageControllers objectAtIndex:index];
    }

    UIViewController *vc = nil;

    switch (index) {
        case 0:
            vc = [self.storyboard instantiateViewControllerWithIdentifier:@"PPBlinkOcrHelpPage1ViewController"];
            break;
        case 1:
            vc = [self.storyboard instantiateViewControllerWithIdentifier:@"PPBlinkOcrHelpPage2ViewController"];
            break;
        case 2:
            vc = [self.storyboard instantiateViewControllerWithIdentifier:@"PPBlinkOcrHelpPage3ViewController"];
            break;

        default:
            break;
    }

    if (vc != nil) {
        [self.pageControllers setObject:vc atIndexedSubscript:index];
    }
    
    return vc;
}

@end
