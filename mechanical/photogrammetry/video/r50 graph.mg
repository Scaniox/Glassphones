{
    "header": {
        "pipelineVersion": "2.2",
        "releaseVersion": "2019.2.0",
        "fileVersion": "1.1",
        "nodesVersions": {
            "Meshing": "3.0",
            "Texturing": "5.0",
            "ImageMatching": "1.0",
            "CameraInit": "2.0",
            "FeatureExtraction": "1.1",
            "FeatureMatching": "2.0",
            "StructureFromMotion": "2.0",
            "PrepareDenseScene": "3.0",
            "DepthMapFilter": "3.0",
            "DepthMap": "2.0",
            "MeshFiltering": "2.0"
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
                "size": 29,
                "split": 1
            },
            "uids": {
                "0": "026f33a740f8a756863d1d8de740930b0046119f"
            },
            "internalFolder": "{cache}/{nodeType}/{uid0}/",
            "inputs": {
                "viewpoints": [
                    {
                        "viewId": 20455773,
                        "poseId": 20455773,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01901.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 136314038,
                        "poseId": 136314038,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01951.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 160486800,
                        "poseId": 160486800,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene00701.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 282548764,
                        "poseId": 282548764,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01301.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 323167612,
                        "poseId": 323167612,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01401.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 394590645,
                        "poseId": 394590645,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01751.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 510607587,
                        "poseId": 510607587,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01001.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 614660772,
                        "poseId": 614660772,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene00751.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 746792408,
                        "poseId": 746792408,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene00601.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 785519142,
                        "poseId": 785519142,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene00801.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1020074247,
                        "poseId": 1020074247,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01101.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1049429640,
                        "poseId": 1049429640,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01351.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1104676139,
                        "poseId": 1104676139,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01801.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1164619235,
                        "poseId": 1164619235,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01701.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1283968274,
                        "poseId": 1283968274,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene00851.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1311600941,
                        "poseId": 1311600941,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01251.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1343242448,
                        "poseId": 1343242448,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01151.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1430520676,
                        "poseId": 1430520676,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01201.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1446341273,
                        "poseId": 1446341273,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01551.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1539772914,
                        "poseId": 1539772914,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene00901.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1739492887,
                        "poseId": 1739492887,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01601.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1822323831,
                        "poseId": 1822323831,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01851.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1860028773,
                        "poseId": 1860028773,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene00951.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1865439864,
                        "poseId": 1865439864,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01451.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1875356350,
                        "poseId": 1875356350,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01651.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1886369179,
                        "poseId": 1886369179,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene02001.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1898130451,
                        "poseId": 1898130451,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene00651.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 1940359100,
                        "poseId": 1940359100,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01501.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    },
                    {
                        "viewId": 2015013291,
                        "poseId": 2015013291,
                        "path": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs/scene01051.png",
                        "intrinsicId": 14981360,
                        "rigId": -1,
                        "subPoseId": -1,
                        "metadata": "\"\""
                    }
                ],
                "intrinsics": [
                    {
                        "intrinsicId": 14981360,
                        "pxInitialFocalLength": -1.0,
                        "pxFocalLength": 772.5483399593904,
                        "type": "radial3",
                        "width": 640,
                        "height": 480,
                        "serialNumber": "C:/Users/alexl/projects/Glassphones/mechanical/photogrammetry/r50 imgs",
                        "principalPoint": {
                            "x": 320.0,
                            "y": 240.0
                        },
                        "initializationMode": "unknown",
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
                "size": 29,
                "split": 1
            },
            "uids": {
                "0": "b693ecbda6344a513a5a6b0bf324e8ef4605089c"
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
                "size": 29,
                "split": 1
            },
            "uids": {
                "0": "b063f8350323c84d92b275a1d2888b310de265f5"
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
                "size": 29,
                "split": 2
            },
            "uids": {
                "0": "961cec140530f7b3f584e456a8b867cfafeffa61"
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
                "size": 29,
                "split": 1
            },
            "uids": {
                "0": "05321de2f97c332c089e527a2c8afd2a22e8c4b3"
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
                "size": 29,
                "split": 1
            },
            "uids": {
                "0": "3e4c19c9a6e097340eab7f3527b9e6b37897db51"
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
                "size": 29,
                "split": 10
            },
            "uids": {
                "0": "4fd98e2220e87a8fe1c7089ad8e6dc06101979ae"
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
                "size": 29,
                "split": 3
            },
            "uids": {
                "0": "be69f848473599ab3ad288b9843b7f50fe8396a6"
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
                "0": "db83591ce1e8f06cfc1e3cb798bf2ff74a9c68ce"
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
                1395,
                0
            ],
            "parallelization": {
                "blockSize": 0,
                "size": 1,
                "split": 1
            },
            "uids": {
                "0": "824bb1fc97e66b3d18760ff6004b31c06b283055"
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
                "0": "2c468ecf00575808510a90f24e992894a4d70658"
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