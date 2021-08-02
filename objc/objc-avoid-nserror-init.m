// objc-avoid-nserror-init
//
// Finds improper initialization of NSError objects.
//
// According to Apple developer document, we should always use factory method
// errorWithDomain:code:userInfo: to create new NSError objects instead of
// [NSError alloc] init]. Otherwise it will lead to a warning message during
// runtime.

#import <Foundation/Foundation.h>
#import <Foundation/NSError.h>

@interface Foo : NSObject
- (void)check;
@end

@implementation Foo
- (void)check {
  NSError *theError = [[NSError alloc] init]; // should warn here
}
@end