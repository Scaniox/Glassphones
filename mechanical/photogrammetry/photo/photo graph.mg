{
    "header": {
        "pipelineVersion": "2.2",
        "releaseVersion": "2019.2.0",
        "fileVersion": "1.1",
        "nodesVersions": {
            "PrepareDenseScene": "3.0",
            "FeatureExtraction": "1.1",
            "MeshFiltering": "2.0",
            "FeatureMatching": "2.0",
            "CameraInit": "2.0",
            "StructureFromMotion": "2.0",
            "DepthMap": "2.0",
            "Texturing": "5.0",
            "DepthMapFilter": "3.0",
            "ImageMatching": "1.0",
            "Meshing": "3.0"
        }
    },
    "graph": {
        "CameraInit_1": {
            "nodeType": "CameraInit",
            "position": [
                0,
                0
            ],
            "parallelization": {
                "blockSize": 0,
                "size": 64,
                "split": 1
            },
            "uids": {
                "0": "38a1536fbf3e12116b7468779bd0641d6f4c686d"
            },
            "internalFolder": "{cache}/{nodeType}/{uid0}/",
            "inputs": {
                "viewpoints": [
                    {
                        "viewId": 22727727,
                        "poseId": 22727727,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175629.jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:29\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.54\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:29\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:29\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.56\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00265252\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 31802105,
                        "poseId": 31802105,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175711(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:11\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.37\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:11\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:11\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.37\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.0030303\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 61783007,
                        "poseId": 61783007,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175643(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:43\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.7\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:43\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:43\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.66\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00248139\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 102646541,
                        "poseId": 102646541,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175714(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:14\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"5.95\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:14\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:14\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"7.98\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00395257\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 152253168,
                        "poseId": 152253168,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175716(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:16\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:16\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:16\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"7.96\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00403226\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 177900454,
                        "poseId": 177900454,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175650(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:50\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.86\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:50\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:50\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.85\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00217391\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 256971151,
                        "poseId": 256971151,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175642(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:42\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.55\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:42\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:42\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.52\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00273973\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 271225539,
                        "poseId": 271225539,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175611.jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:11\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.77\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:11\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:11\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"3\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.78\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.0022831\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 286981042,
                        "poseId": 286981042,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175712(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:12\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.24\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:12\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:12\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.29\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00320513\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 308587086,
                        "poseId": 308587086,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175713(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:13\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.1\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:13\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:13\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.13\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00358423\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 339865800,
                        "poseId": 339865800,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175641(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:41\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.37\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:41\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:41\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.35\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00306748\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 351163884,
                        "poseId": 351163884,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175625(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:25\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.71\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:25\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:25\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.7\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00241546\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 355071552,
                        "poseId": 355071552,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175639(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:39\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.22\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:39\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:39\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.2\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00341297\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 369281628,
                        "poseId": 369281628,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175640(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:40\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.23\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:40\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:40\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.2\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00341297\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 397217338,
                        "poseId": 397217338,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175635(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:35\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.33\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:35\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:35\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.38\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.003003\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 498073649,
                        "poseId": 498073649,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175628.jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:28\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.66\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:28\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:28\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.7\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00241546\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 532412952,
                        "poseId": 532412952,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175617(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:17\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.86\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:17\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:17\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.82\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00222222\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 566440934,
                        "poseId": 566440934,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175613(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:13\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.78\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:13\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:13\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.78\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.0022831\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 790973902,
                        "poseId": 790973902,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175612.jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:12\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.81\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:12\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:12\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.78\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.0022831\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 942170023,
                        "poseId": 942170023,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175616(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:16\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.8\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:16\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:16\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.77\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00229358\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1040065685,
                        "poseId": 1040065685,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175702(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:02\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.18\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:02\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:02\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.18\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00344828\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1063653319,
                        "poseId": 1063653319,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175710(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:10\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.52\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:10\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:10\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.51\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00274725\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1103321913,
                        "poseId": 1103321913,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175630(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:30\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.46\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:30\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:30\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.48\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00280899\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1112659761,
                        "poseId": 1112659761,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175657(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:57\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.09\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:57\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:57\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.11\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00362319\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1113613468,
                        "poseId": 1113613468,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175649(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:49\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.81\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:49\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:49\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.75\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00232019\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1116963897,
                        "poseId": 1116963897,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175655(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:55\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.67\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:55\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:55\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.73\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00236407\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1125987063,
                        "poseId": 1125987063,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175656(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:56\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.35\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:56\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:56\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.34\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00308642\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1155971086,
                        "poseId": 1155971086,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175654(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:54\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.77\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:54\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:54\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.78\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.0022779\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1175344788,
                        "poseId": 1175344788,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175632(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:32\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.4\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:32\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:32\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.38\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.003003\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1199171366,
                        "poseId": 1199171366,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175622(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:22\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.76\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:22\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:22\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.76\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00231481\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1237259653,
                        "poseId": 1237259653,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175646.jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:46\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.55\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:46\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:46\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.51\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00274725\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1242056663,
                        "poseId": 1242056663,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175659.jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:59\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"5.93\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:59\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:59\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"7.91\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00414938\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1249290596,
                        "poseId": 1249290596,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175623(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:23\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.74\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:23\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:23\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.76\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00231481\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1295243340,
                        "poseId": 1295243340,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175614(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:14\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.77\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:14\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:14\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.78\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.0022831\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1303281967,
                        "poseId": 1303281967,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175633(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:33\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.37\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:33\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:33\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.38\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.003003\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1338512535,
                        "poseId": 1338512535,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175615(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:15\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.72\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:15\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:15\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.71\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00239808\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1338687873,
                        "poseId": 1338687873,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175651(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:51\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.93\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:51\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:51\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.85\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00217391\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1360762196,
                        "poseId": 1360762196,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175621(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:21\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.8\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:21\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:21\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.84\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00217865\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1425255407,
                        "poseId": 1425255407,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175700(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:00\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.2\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:00\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:00\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.19\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00343643\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1484280532,
                        "poseId": 1484280532,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175707(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:07\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.59\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:07\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:07\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.52\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.0027248\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1493258122,
                        "poseId": 1493258122,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175706(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:06\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.58\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:06\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:06\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.52\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.0027248\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1511173744,
                        "poseId": 1511173744,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175653(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:53\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.84\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:53\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:53\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.85\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00217391\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1526957505,
                        "poseId": 1526957505,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175631(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:31\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.44\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:31\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:31\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.48\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00280899\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1545789569,
                        "poseId": 1545789569,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175658(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:58\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.04\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:58\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:58\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.04\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00380228\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1560870966,
                        "poseId": 1560870966,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175652(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:52\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.91\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:52\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:52\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.85\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00217391\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1564385305,
                        "poseId": 1564385305,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175645(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:45\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.69\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:45\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:45\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.7\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00240385\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1615523591,
                        "poseId": 1615523591,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175637(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:37\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.18\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:37\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:37\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.22\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.003367\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1646101874,
                        "poseId": 1646101874,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175715.jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:15\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"5.83\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:15\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:15\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"7.77\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00456621\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1664004248,
                        "poseId": 1664004248,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175618(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:18\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"7\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:18\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:18\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.96\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00200803\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1665705109,
                        "poseId": 1665705109,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175636(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:36\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.23\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:36\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:36\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.22\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.003367\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1750505822,
                        "poseId": 1750505822,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175647.jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:47\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.54\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:47\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:47\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.51\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00274725\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1850375413,
                        "poseId": 1850375413,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175624(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:24\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.7\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:24\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:24\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.76\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00231481\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1850568858,
                        "poseId": 1850568858,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175638(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:38\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.18\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:38\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:38\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.14\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.0035461\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1895546283,
                        "poseId": 1895546283,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175634(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:34\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.38\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:34\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:34\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.38\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.003003\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1907434793,
                        "poseId": 1907434793,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175626(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:26\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.66\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:26\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:26\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.7\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00241546\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1913901017,
                        "poseId": 1913901017,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175627(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:27\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.64\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:27\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:27\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.7\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00241546\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1917293364,
                        "poseId": 1917293364,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175705(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:05\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.53\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:05\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:05\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.52\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.0027248\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1975487486,
                        "poseId": 1975487486,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175644(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:44\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.66\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:44\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:44\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.65\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00248756\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1985245786,
                        "poseId": 1985245786,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175701(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:01\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.3\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:01\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:01\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.29\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00319489\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 1998942535,
                        "poseId": 1998942535,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175620(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:20\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.91\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:20\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:20\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.96\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00200803\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 2026061171,
                        "poseId": 2026061171,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175619(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:56:19\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.99\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:56:19\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:56:19\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.96\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00200803\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 2050995335,
                        "poseId": 2050995335,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175703(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:03\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.21\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:03\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:03\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.18\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00344828\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 2115999314,
                        "poseId": 2115999314,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175708.jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:08\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.7\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:08\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:08\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.63\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00252525\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    },
                    {
                        "viewId": 2128018622,
                        "poseId": 2128018622,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs/20210727_175709(0).jpg",
                        "intrinsicId": 4119923295,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "{\"AliceVision:SensorWidthEstimation\": \"5.791198\", \"DateTime\": \"2021:07:27 17:57:09\", \"Exif:ApertureValue\": \"1.85\", \"Exif:BrightnessValue\": \"6.58\", \"Exif:ColorSpace\": \"1\", \"Exif:DateTimeDigitized\": \"2021:07:27 17:57:09\", \"Exif:DateTimeOriginal\": \"2021:07:27 17:57:09\", \"Exif:ExifVersion\": \"0220\", \"Exif:ExposureBiasValue\": \"0\", \"Exif:ExposureMode\": \"0\", \"Exif:ExposureProgram\": \"2\", \"Exif:Flash\": \"0\", \"Exif:FlashPixVersion\": \"0100\", \"Exif:FocalLength\": \"4.3\", \"Exif:FocalLengthIn35mmFilm\": \"28\", \"Exif:ImageUniqueID\": \"A16LSIA00VM A16LSJL02SM\\n\", \"Exif:MaxApertureValue\": \"1.85\", \"Exif:MeteringMode\": \"2\", \"Exif:PhotographicSensitivity\": \"40\", \"Exif:PixelXDimension\": \"3264\", \"Exif:PixelYDimension\": \"1836\", \"Exif:SceneCaptureType\": \"0\", \"Exif:ShutterSpeedValue\": \"8.63\", \"Exif:WhiteBalance\": \"0\", \"Exif:YCbCrPositioning\": \"1\", \"ExposureTime\": \"0.00252525\", \"FNumber\": \"1.9\", \"Make\": \"samsung\", \"Model\": \"SM-G925F\", \"Orientation\": \"1\", \"ResolutionUnit\": \"none\", \"Software\": \"G925FXXU6ERF5\", \"XResolution\": \"72\", \"YResolution\": \"72\", \"jpeg:subsampling\": \"4:2:2\", \"oiio:ColorSpace\": \"sRGB\"}"
                    }
                ],
                "intrinsics": [
                    {
                        "intrinsicId": 4119923295,
                        "pxInitialFocalLength": 2423.5401950293863,
                        "pxFocalLength": 2423.5401950293863,
                        "type": "radial3",
                        "width": 3264,
                        "height": 1836,
                        "serialNumber": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/photo/imgs_samsung_SM-G925F",
                        "principalPoint": {
                            "x": 1632.0,
                            "y": 918.0
                        },
                        "initializationMode": "estimated",
                        "distortionParams": [
                            0.0,
                            0.0,
                            0.0
                        ],
                        "locked": false
                    }
                ],
                "sensorDatabase": "C:\\Users\\alexl\\projects\\photogrammetry\\meshroom\\aliceVision\\share\\aliceVision\\cameraSensors.db",
                "defaultFieldOfView": 45.0,
                "groupCameraFallback": "folder",
                "verboseLevel": "info"
            },
            "outputs": {
                "output": "{cache}/{nodeType}/{uid0}/cameraInit.sfm"
            }
        },
        "FeatureExtraction_1": {
            "nodeType": "FeatureExtraction",
            "position": [
                155,
                0
            ],
            "parallelization": {
                "blockSize": 40,
                "size": 64,
                "split": 2
            },
            "uids": {
                "0": "498904acc1d041c8323ceafd515678640a11d699"
            },
            "internalFolder": "{cache}/{nodeType}/{uid0}/",
            "inputs": {
                "input": "{CameraInit_1.output}",
                "describerTypes": [
                    "sift"
                ],
                "describerPreset": "normal",
                "forceCpuExtraction": true,
                "verboseLevel": "info"
            },
            "outputs": {
                "output": "{cache}/{nodeType}/{uid0}/"
            }
        },
        "ImageMatching_1": {
            "nodeType": "ImageMatching",
            "position": [
                310,
                0
            ],
            "parallelization": {
                "blockSize": 0,
                "size": 64,
                "split": 1
            },
            "uids": {
                "0": "0d1bc4acf8d895246b2e9b26d2ca10b898d05245"
            },
            "internalFolder": "{cache}/{nodeType}/{uid0}/",
            "inputs": {
                "input": "{FeatureExtraction_1.input}",
                "featuresFolders": [
                    "{FeatureExtraction_1.output}"
                ],
                "tree": "C:\\Users\\alexl\\projects\\photogrammetry\\meshroom\\aliceVision\\share\\aliceVision\\vlfeat_K80L3.SIFT.tree",
                "weights": "",
                "minNbImages": 200,
                "maxDescriptors": 500,
                "nbMatches": 50,
                "verboseLevel": "info"
            },
            "outputs": {
                "output": "{cache}/{nodeType}/{uid0}/imageMatches.txt"
            }
        },
        "FeatureMatching_1": {
            "nodeType": "FeatureMatching",
            "position": [
                465,
                0
            ],
            "parallelization": {
                "blockSize": 20,
                "size": 64,
                "split": 4
            },
            "uids": {
                "0": "8e7a8b733a39d459208570b47af6798179f21a7f"
            },
            "internalFolder": "{cache}/{nodeType}/{uid0}/",
            "inputs": {
                "input": "{ImageMatching_1.input}",
                "featuresFolders": "{ImageMatching_1.featuresFolders}",
                "imagePairsList": "{ImageMatching_1.output}",
                "describerTypes": [
                    "sift"
                ],
                "photometricMatchingMethod": "ANN_L2",
                "geometricEstimator": "acransac",
                "geometricFilterType": "fundamental_matrix",
                "distanceRatio": 0.8,
                "maxIteration": 2048,
                "geometricError": 0.0,
                "maxMatches": 0,
                "savePutativeMatches": false,
                "guidedMatching": false,
                "exportDebugFiles": false,
                "verboseLevel": "info"
            },
            "outputs": {
                "output": "{cache}/{nodeType}/{uid0}/"
            }
        },
        "StructureFromMotion_1": {
            "nodeType": "StructureFromMotion",
            "position": [
                620,
                0
            ],
            "parallelization": {
                "blockSize": 0,
                "size": 64,
                "split": 1
            },
            "uids": {
                "0": "d71c1582ed01c90abd0e8f21b0806b4d62578cae"
            },
            "internalFolder": "{cache}/{nodeType}/{uid0}/",
            "inputs": {
                "input": "{FeatureMatching_1.input}",
                "featuresFolders": "{FeatureMatching_1.featuresFolders}",
                "matchesFolders": [
                    "{FeatureMatching_1.output}"
                ],
                "describerTypes": [
                    "sift"
                ],
                "localizerEstimator": "acransac",
                "localizerEstimatorMaxIterations": 4096,
                "localizerEstimatorError": 0.0,
                "lockScenePreviouslyReconstructed": false,
                "useLocalBA": true,
                "localBAGraphDistance": 1,
                "maxNumberOfMatches": 0,
                "minInputTrackLength": 2,
                "minNumberOfObservationsForTriangulation": 2,
                "minAngleForTriangulation": 3.0,
                "minAngleForLandmark": 2.0,
                "maxReprojectionError": 4.0,
                "minAngleInitialPair": 5.0,
                "maxAngleInitialPair": 40.0,
                "useOnlyMatchesFromInputFolder": false,
                "useRigConstraint": true,
                "lockAllIntrinsics": false,
                "initialPairA": "",
                "initialPairB": "",
                "interFileExtension": ".abc",
                "verboseLevel": "info"
            },
            "outputs": {
                "output": "{cache}/{nodeType}/{uid0}/sfm.abc",
                "outputViewsAndPoses": "{cache}/{nodeType}/{uid0}/cameras.sfm",
                "extraInfoFolder": "{cache}/{nodeType}/{uid0}/"
            }
        },
        "PrepareDenseScene_1": {
            "nodeType": "PrepareDenseScene",
            "position": [
                775,
                0
            ],
            "parallelization": {
                "blockSize": 40,
                "size": 64,
                "split": 2
            },
            "uids": {
                "0": "d4f40fa8ae4d8e7a0b4a9b02b9dc244c88c7f1a9"
            },
            "internalFolder": "{cache}/{nodeType}/{uid0}/",
            "inputs": {
                "input": "{StructureFromMotion_1.output}",
                "imagesFolders": [],
                "outputFileType": "exr",
                "saveMetadata": true,
                "saveMatricesTxtFiles": false,
                "evCorrection": false,
                "verboseLevel": "info"
            },
            "outputs": {
                "output": "{cache}/{nodeType}/{uid0}/",
                "outputUndistorted": "{cache}/{nodeType}/{uid0}/*.{outputFileTypeValue}"
            }
        },
        "DepthMap_1": {
            "nodeType": "DepthMap",
            "position": [
                930,
                0
            ],
            "parallelization": {
                "blockSize": 3,
                "size": 64,
                "split": 22
            },
            "uids": {
                "0": "02fd681ff2a072b878f8303e52b0faceaa19335a"
            },
            "internalFolder": "{cache}/{nodeType}/{uid0}/",
            "inputs": {
                "input": "{PrepareDenseScene_1.input}",
                "imagesFolder": "{PrepareDenseScene_1.output}",
                "downscale": 2,
                "minViewAngle": 2.0,
                "maxViewAngle": 70.0,
                "sgmMaxTCams": 10,
                "sgmWSH": 4,
                "sgmGammaC": 5.5,
                "sgmGammaP": 8.0,
                "refineMaxTCams": 6,
                "refineNSamplesHalf": 150,
                "refineNDepthsToRefine": 31,
                "refineNiters": 100,
                "refineWSH": 3,
                "refineSigma": 15,
                "refineGammaC": 15.5,
                "refineGammaP": 8.0,
                "refineUseTcOrRcPixSize": false,
                "exportIntermediateResults": false,
                "nbGPUs": 0,
                "verboseLevel": "info"
            },
            "outputs": {
                "output": "{cache}/{nodeType}/{uid0}/"
            }
        },
        "DepthMapFilter_1": {
            "nodeType": "DepthMapFilter",
            "position": [
                1085,
                0
            ],
            "parallelization": {
                "blockSize": 10,
                "size": 64,
                "split": 7
            },
            "uids": {
                "0": "24b79df3ac3274988167803b87b50ed05e469bb3"
            },
            "internalFolder": "{cache}/{nodeType}/{uid0}/",
            "inputs": {
                "input": "{DepthMap_1.input}",
                "depthMapsFolder": "{DepthMap_1.output}",
                "minViewAngle": 2.0,
                "maxViewAngle": 70.0,
                "nNearestCams": 10,
                "minNumOfConsistentCams": 3,
                "minNumOfConsistentCamsWithLowSimilarity": 4,
                "pixSizeBall": 0,
                "pixSizeBallWithLowSimilarity": 0,
                "computeNormalMaps": false,
                "verboseLevel": "info"
            },
            "outputs": {
                "output": "{cache}/{nodeType}/{uid0}/"
            }
        },
        "Meshing_1": {
            "nodeType": "Meshing",
            "position": [
                1240,
                0
            ],
            "parallelization": {
                "blockSize": 0,
                "size": 1,
                "split": 1
            },
            "uids": {
                "0": "114f4ff6afbac0e45e9cbe46789cd0630ba7c6f8"
            },
            "internalFolder": "{cache}/{nodeType}/{uid0}/",
            "inputs": {
                "input": "{DepthMapFilter_1.input}",
                "depthMapsFolder": "{DepthMapFilter_1.depthMapsFolder}",
                "depthMapsFilterFolder": "{DepthMapFilter_1.output}",
                "estimateSpaceFromSfM": true,
                "estimateSpaceMinObservations": 3,
                "estimateSpaceMinObservationAngle": 10,
                "maxInputPoints": 50000000,
                "maxPoints": 5000000,
                "maxPointsPerVoxel": 1000000,
                "minStep": 2,
                "partitioning": "singleBlock",
                "repartition": "multiResolution",
                "angleFactor": 15.0,
                "simFactor": 15.0,
                "pixSizeMarginInitCoef": 2.0,
                "pixSizeMarginFinalCoef": 4.0,
                "voteMarginFactor": 4.0,
                "contributeMarginFactor": 2.0,
                "simGaussianSizeInit": 10.0,
                "simGaussianSize": 10.0,
                "minAngleThreshold": 1.0,
                "refineFuse": true,
                "addLandmarksToTheDensePointCloud": false,
                "colorizeOutput": false,
                "saveRawDensePointCloud": false,
                "verboseLevel": "info"
            },
            "outputs": {
                "outputMesh": "{cache}/{nodeType}/{uid0}/mesh.obj",
                "output": "{cache}/{nodeType}/{uid0}/densePointCloud.abc"
            }
        },
        "MeshFiltering_1": {
            "nodeType": "MeshFiltering",
            "position": [
                1401,
                15
            ],
            "parallelization": {
                "blockSize": 0,
                "size": 1,
                "split": 1
            },
            "uids": {
                "0": "870f467cece08f58ffa68361e97a56e03c333479"
            },
            "internalFolder": "{cache}/{nodeType}/{uid0}/",
            "inputs": {
                "inputMesh": "{Meshing_1.outputMesh}",
                "removeLargeTrianglesFactor": 60.0,
                "keepLargestMeshOnly": false,
                "iterations": 5,
                "lambda": 1.0,
                "verboseLevel": "info"
            },
            "outputs": {
                "outputMesh": "{cache}/{nodeType}/{uid0}/mesh.obj"
            }
        },
        "Texturing_1": {
            "nodeType": "Texturing",
            "position": [
                1550,
                0
            ],
            "parallelization": {
                "blockSize": 0,
                "size": 1,
                "split": 1
            },
            "uids": {
                "0": "7dbf5fcf75c8e01fff2a9cd4a0f2802c9296240c"
            },
            "internalFolder": "{cache}/{nodeType}/{uid0}/",
            "inputs": {
                "input": "{Meshing_1.output}",
                "imagesFolder": "{DepthMap_1.imagesFolder}",
                "inputMesh": "{MeshFiltering_1.outputMesh}",
                "textureSide": 8192,
                "downscale": 1,
                "outputTextureFileType": "png",
                "unwrapMethod": "Basic",
                "useUDIM": true,
                "fillHoles": false,
                "padding": 5,
                "correctEV": false,
                "useScore": true,
                "processColorspace": "sRGB",
                "multiBandDownscale": 4,
                "multiBandNbContrib": {
                    "high": 1,
                    "midHigh": 5,
                    "midLow": 10,
                    "low": 0
                },
                "bestScoreThreshold": 0.1,
                "angleHardThreshold": 90.0,
                "forceVisibleByAllVertices": false,
                "flipNormals": false,
                "visibilityRemappingMethod": "PullPush",
                "verboseLevel": "info"
            },
            "outputs": {
                "output": "{cache}/{nodeType}/{uid0}/",
                "outputMesh": "{cache}/{nodeType}/{uid0}/texturedMesh.obj",
                "outputMaterial": "{cache}/{nodeType}/{uid0}/texturedMesh.mtl",
                "outputTextures": "{cache}/{nodeType}/{uid0}/texture_*.{outputTextureFileTypeValue}"
            }
        }
    }
}