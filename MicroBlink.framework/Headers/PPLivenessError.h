//
//  PPLivenessError.h
//  BlinkIdFramework
//
//  Created by Jura on 06/09/16.
//  Copyright © 2016 MicroBlink Ltd. All rights reserved.
//

#ifndef PPLivenessError_h
#define PPLivenessError_h

/**
 * Enumeration of Liveness Errors
 */
typedef NS_ENUM(NSInteger, PPLivenessError) {

    /**
     *  Eyes are not in ideal region of interest
     */
    PPLivenessErrorFaceNotInRoi,

    /**
     *  Angle Yaw is too large
     */
    PPLivenessErrorFaceAngleYawLarge,

    /**
     *  Angle Yaw is too smalle
     */
    PPLivenessErrorFaceAngleYawSmall,

    /**
     *  Angle Pitch is too large
     */
    PPLivenessErrorFaceAnglePitchLarge,

    /**
     *  Angle Pitch is too small
     */
    PPLivenessErrorFaceAnglePitchSmall,

    /**
     *  Angle Roll is too large
     */
    PPLivenessErrorFaceAngleRollLarge,

    /**
     *  Angle Roll is too small
     */
    PPLivenessErrorFaceAngleRollSmall,

    /**
     *  Face is too close
     */
    PPLivenessErrorFaceTooClose,

    /**
     *  Face is too far
     */
    PPLivenessErrorFaceTooFar,

    /**
     * Face is not in the image
     */
    PPLivenessErrorNoFace,

    /**
     *  No error - Success!
     */
    PPLivenessErrorSuccess,
};

#endif /* PPLivenessError_h */
