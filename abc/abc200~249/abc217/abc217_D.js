"use strict";

const { builtinModules } = require("module");

const searchLength = (point, thisMokuzai) => {
  if (thisMokuzai.leftEnd)
  if (thisMokuzai.slashPoint === 0) {
    console.log(thisMokuzai.length);
  } else if (thisMokuzai.slashPoint < point) {
    searchLength(point, thisMokuzai.right);
  } else {
    searchLength(point, thisMokuzai.left);
  }
  return;
};
const slash = (point, thisMokuzai) => {
  if (thisMokuzai.slashPoint === 0) {
    thisMokuzai.slashPoint = point;
    thisMokuzai.left = {
      length: point - thisMokuzai.leftEnd,
      rightEnd: point,
      leftEnd: thisMokuzai.leftEnd,
      left: {},
      right: {},
      slashPoint: 0,
    };
    thisMokuzai.right = {
      length: thisMokuzai.rightEnd - point,
      rightEnd: thisMokuzai.rightEnd,
      leftEnd: point,
      left: {},
      right: {},
      slashPoint: 0,
    };
  } else if (thisMokuzai.slashPoint < point) {
    slash(point, thisMokuzai.right);
  } else {
    slash(point, thisMokuzai.left);
  }
  return;
};
const twopow = (n) => {
  let x = 1;
  while(x < n) {
    x *= 2;
  }
  return x;
}
const build = (thisMokuzai) => {
  if (this.Mokuzai.length >= 2) {
    const mid = (thisMokuzai.leftEnd + thisMokuzai.rightEnd) / 2;
    thisMokuzai.slashPoint = mid;
    thisMokuzai.left = {
      length: thisMokuzai.length / 2,
      rightEnd: mid,
      leftEnd: thisMokuzai.leftEnd,
      left: {},
      right: {},
      slashPoint: 0,
    };
    thisMokuzai.right = {
      length: thisMokuzai.length / 2,
      rightEnd: thisMokuzai.rightEnd,
      leftEnd: mid + 1,
      left: {},
      right: {},
      slashPoint: 0,
    };
    build(thisMokuzai.left);
    build(thisMokuzai.right);
  }
  return;
};

const main = (arg) => {
  const input = arg.trim().split("\n");
  const [LString, QString] = input[0].split(" ");

  const L = parseInt(LString);
  const Q = parseInt(QString);

  const qArrayString = input.filter((n, i) => i !== 0);
  let qArray = qArrayString.map((n) => {
    const a = n.split(" ");
    const thisQ = {
      c: parseInt(a[0]),
      x: parseInt(a[1]),
    };
    return thisQ;
  });

  // twopow(n) = min({ 2^x | 2^x >= n })
  L = twopow(L);

  let mokuzai = {
    length: L,
    leftEnd: 0,
    rightEnd: L,
    left: {},
    right: {},
    slashPoint: 0,
  };

  build(mokuzai);

  for (let i = 0; i < Q; i++) {
    if (qArray[i].c === 2) {
      searchLength(qArray[i].x, mokuzai);
    } else {
      slash(qArray[i].x, mokuzai);
    }
  }
};

main(require("fs").readFileSync("/dev/stdin", "utf8"));
