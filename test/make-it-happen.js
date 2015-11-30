var assert = require('chai').assert;
var codecheck = require('codecheck');

function run(expected, done) {
  var app = codecheck.consoleApp('./bin/outofmemory');
  app.runAndVerify([], function (result) {
    console.log('result:', result);
    assert(null, result.getMessage());
    done();
  });
}

describe('Out of memory', function () {
  it('should be killed', function (done) {
    run(done);
  });
});
