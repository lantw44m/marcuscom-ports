--- JavaScriptCore/jit/JITOpcodes.cpp.orig	2009-10-19 08:35:41.000000000 -0400
+++ JavaScriptCore/jit/JITOpcodes.cpp	2009-10-19 08:36:09.000000000 -0400
@@ -270,7 +270,7 @@ void JIT::privateCompileCTIMachineTrampo
     emitGetFromCallFrameHeaderPtr(RegisterFile::ReturnPC, regT1);
     move(ImmPtr(&globalData->exceptionLocation), regT2);
     storePtr(regT1, regT2);
-    move(ImmPtr(reinterpret_cast<void*>(ctiVMThrowTrampoline)), regT2);
+    move(ImmPtr((void*)(ctiVMThrowTrampoline)), regT2);
     emitGetFromCallFrameHeaderPtr(RegisterFile::CallerFrame, callFrameRegister);
     poke(callFrameRegister, OBJECT_OFFSETOF(struct JITStackFrame, callFrame) / sizeof (void*));
     restoreReturnAddressBeforeReturn(regT2);
