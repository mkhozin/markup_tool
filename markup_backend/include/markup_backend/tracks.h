#pragma once

class TrackContainer {
public:
    TrackContainer() = delete;
    explicit TrackContainer(size_t video_length);
    // void add_track(Track);
    // get all detections at frame_index
    // iterate through all tracks
    // Get track by id
    // Merge tracks
    // Split tracks
    // Delete tracks
    // Re-id tracks
private:
    size_t video_length_;
    // tracks
};
