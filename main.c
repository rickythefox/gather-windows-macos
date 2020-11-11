#include <stdio.h>
#include <ApplicationServices/ApplicationServices.h>

void GetDisplays(CGDirectDisplayID* mainDisplayId, CGDirectDisplayID* secondaryDisplayId) {
    CGDirectDisplayID t = CGMainDisplayID();
    *mainDisplayId = CGMainDisplayID();
    CGDirectDisplayID onlineDisplays[10];
    uint32_t nOnlineDisplays;

    CGDisplayErr err = CGGetOnlineDisplayList(10, onlineDisplays, &nOnlineDisplays);
    if (err != 0) {
        printf("Error getting online displays: %d\n", err);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nOnlineDisplays; i++) {
        if (onlineDisplays[i] != *mainDisplayId) {
            *secondaryDisplayId = onlineDisplays[i];
            break;
        }
    }
}

void ToggleMirroring(bool on, CGDirectDisplayID mainDisplayId, CGDirectDisplayID secondaryDisplayId) {
    // Begin configuration
    CGDisplayConfigRef configRef;
    CGError err = CGBeginDisplayConfiguration(&configRef);
    if (err != 0) {
        printf("Error initiating display configuration: %d\n", err);
        exit(EXIT_FAILURE);
    }

    // Mirror displays or cancel mirroring
    if (!on)
        mainDisplayId = kCGNullDirectDisplay;
    err = CGConfigureDisplayMirrorOfDisplay(configRef, secondaryDisplayId, mainDisplayId);
    if (err != 0) {
        printf("Error configuring displays: %d\n", err);
        exit(EXIT_FAILURE);
    }

    // Apply the changes
    err = CGCompleteDisplayConfiguration(configRef, kCGConfigurePermanently);
    if (err != 0) {
        printf("Error applying configuration: %d\n", err);
        exit(EXIT_FAILURE);
    }
}

int main() {
    CGDirectDisplayID mainDisplayId, secondaryDisplayId;
    GetDisplays(&mainDisplayId, &secondaryDisplayId);

    bool alreadyMirrored = CGDisplayIsInMirrorSet(mainDisplayId);
    if (alreadyMirrored) {
        printf("Displays mirrored, will not toggle\n");
        exit(EXIT_SUCCESS);
    }

    if (mainDisplayId <= 0 || secondaryDisplayId <= 0) {
        printf("Can't find a main and a secondary display\n");
        exit(EXIT_FAILURE);
    }

    ToggleMirroring(true, mainDisplayId, secondaryDisplayId);
    ToggleMirroring(false, mainDisplayId, secondaryDisplayId);

    return EXIT_SUCCESS;
}

