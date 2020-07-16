#include "ChatViewport.h"
#include <vector>

ChatViewport::ChatViewport(SdlWindow& window, int x, int y, int w, int h) :
  SdlViewport(window, x, y, w, h) {}

void ChatViewport::paint(EntityList& values) {
  fit();

  for (unsigned int i = 0; i < values.size(); i++)
    values[i]->paint(wScale, hScale);
}

ChatViewport::~ChatViewport() {}
