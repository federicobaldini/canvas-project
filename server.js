// Express
import express from "express";
const server = express();

// Serve static files from /public
server.use(
  express.static("public", {
    setHeaders: (res, path, stat) => {
      // Serve .wasm files with correct mime type
      if (path.endsWith(".wasm")) {
        res.set("Content-type", "application/wasm");
      }
    },
  })
);

// Start server
server.listen(2222, () => console.log("Server running on port 2222!"));
