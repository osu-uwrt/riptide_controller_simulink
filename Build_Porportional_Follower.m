% Generate Code for the porportional follower and the cmake required to
% build it

model_name = "TestController";
subsystem_name = "Porportional_Follower_Test"; %This should be the name in the Model not the file name

%open model
open(model_name + ".slx")

%it is important that the model params are set to build with the grt model
%and the "generate makefile is selected"

%if building only a subsystem, ensure the subsystem is a referenced
%subsystem and an atomic subsystem

%generate code for the subsystem
slbuild(model_name + "/" + subsystem_name) % Model/Subsystem

build_folder = pwd() + "/" + subsystem_name + "_ert_shrlib_rtw";
codebuild(build_folder, 'BuildMethod', 'cmake');
