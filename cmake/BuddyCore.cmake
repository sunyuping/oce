
AUX_SOURCE_DIRECTORY("../BuddyEntry/src" BUILD_BuddyEntry_SRC_CPP_SOURCE )
AUX_SOURCE_DIRECTORY("../BuddyCore/src" BUILD_BuddyCore_SRC_CPP_SOURCE )
ADD_LIBRARY( "BuddyCore" SHARED EXCLUDE_FROM_ALL ${BUILD_BuddyEntry_SRC_CPP_SOURCE} ${BUILD_BuddyCore_SRC_CPP_SOURCE})
#ADD_EXECUTABLE( "BuddyCore" EXCLUDE_FROM_ALL ${BUILD_BuddyEntry_SRC_CPP_SOURCE} ${BUILD_BuddyCore_SRC_CPP_SOURCE})
#TARGET_LINK_LIBRARIES( "BuddyCore" OceCxxAdapterBuddyCoreLogicAdapter OceCxxAdapterActiveTrackAdapter OceCxxAdapterActiveTrackFacadeAdapter OceCxxAdapterXceLoggerAdapter OceCxxAdapterUserCountAdapter ReplicaCluster IceExt OceSliceXceStorm DbCxxPool OceSliceReplicaCluster OceSliceSubjectObserver OceSliceActiveTrack OceSliceUserCount OceSliceBuddyCore UtilCxx UtilSlice)
ADD_DEPENDENCIES( ReplicaCluster OceSliceReplicaCluster OceSliceSubjectObserver)
TARGET_LINK_LIBRARIES( "BuddyCore" 
	ReplicaCluster  OceSliceReplicaCluster OceSliceSubjectObserver
	OceCxxAdapterBuddyCoreLogicAdapter OceSliceBuddyCore
	OceCxxAdapterActiveTrackAdapter OceCxxAdapterActiveTrackFacadeAdapter OceCxxAdapterXceLoggerAdapter OceSliceActiveTrack
	OceCxxAdapterUserCountAdapter OceSliceUserCount
	OceCxxAdapterMonitorAdapter
  IceExt OceSliceXceStorm DbCxxPool OceSlice UtilCxx UtilSlice)
