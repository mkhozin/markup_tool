#pragma once

#include <string>

#include "markup_backend/nn_model.h"
#include "markup_backend/tracks.h"
#include "markup_backend/video.h"

struct PipelineRunParams {
    std::string detector_model_path;
    std::string id_model_path; // maybe path to python file?
};

class MarkUp {
public:
    MarkUp() = delete;
    explicit MarkUp(const PipelineRunParams& params) :
        detector_(params.detector_model_path),
        id_model_(params.id_model_path) {

    }

    TrackContainer run(const Video& video);
    void RunModel(const std::string python_script_path) {
        // create json with tracks
        std::string command = "python ";
        command += python_script_path;
        system(command.c_str());
    }
    
private:
    Detector detector_;
    IDModel id_model_;
};
